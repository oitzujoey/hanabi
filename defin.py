import nltk, pprint
nltk.download('wordnet')

from nltk.corpus import wordnet

syns = wordnet.synsets("screen")
print(syns[0].definition())

import spacy
from nltk import Tree

en_nlp = spacy.load('en_core_web_sm')

doc = en_nlp(syns[0].definition())
#Trying to think of places knowing your palette that you would like
#doc = en_nlp("The way I speak is weird because when you parse the way I speak using these trees they tend to either be extremely wide or tall")

def to_custom_tree(node):

    t = wordnet.synsets(node.orth_)
    if node.orth_ in ["in", "be"]: return []
    else:
        if len(t) > 1: t = t[0]
        elif len(str(t)) == 0: t = node.orth_

    if node.n_lefts + node.n_rights > 0:
        if str(t) != '[]':
            m = [t]
        else:
            m = []
        for child in node.children:
            tt = to_custom_tree(child)
            if str(tt) != '[]':
                m.append(tt)        
        return m
    else:
        return t


pprint.pprint([to_custom_tree(sent.root) for sent in doc.sents])