import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives="positive-words.txt", negatives="negative-words.txt"):
        """Initialize Analyzer."""

        self.pf = open(positives, "r")
        self.nf = open(negatives, "r")
        self.poscounter = 0
        self.negcounter = 0
        self.score = 0

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        
        
        for i in range(len(tokens)):
            
            if tokens[i] in self.pf.read():
                self.poscounter += 1
      
            elif tokens[i] in self.nf.read():
                self.negcounter += 1
                
            else: 
                self.score = self.score
                  
        self.score = self.poscounter - self.negcounter
           
        return self.score