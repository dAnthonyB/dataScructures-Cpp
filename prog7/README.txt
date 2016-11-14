Program Function:
It takes a folder with documents compares chunks of their text using a user defined size to
determine how many words are in each chunk of text. It then counts the number of similar comparisons
and outputs the documents that share more than the user defined amount of similarities to file. It also
outputs the filenames, when it's finished hashing, when it's finished checking collisions, the smallest 
hash value, the biggest hash values, and the number of hashes to the console.

Make by typing: make
Use by typing: ./plagiarismCatcher "folder name" "word chunk size" "number of collisions"
examples:
./plagiarismCatcher "sm_doc_set" 5 300 
./plagiarismCatcher "med_doc_set" 6 250
./plagiarismCatcher "big_doc_set" 7 200

It has trouble handling a hash table > 200,000
Takes a couple minutes to process the big_doc_set's collisions.
Everything else should work fine.
