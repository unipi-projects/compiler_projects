------------------------------------


# Next Time

PrintTree() ~> function that prints the syntax tree given MT(the left variable of M) and the production.




# Done

[X] Εκτύπωση σε μορφή δέντρου(είσοδος)


[X] Έλεγχος input    ~> Εγκυρος ~> Τελειώνει όταν το Stack είναι κενό
[X]                 ~> Μη Εγκυρος ~> Όταν το M δεν έχει περίπτωση


 



## Done

[X]Function που τσεκάρει σε περίπτωση που η CheckTopElementOfStack:

[X]Αν επέστρεψε false(Μη τερματικό) ~> Καλεί την M(char mt, char t) και μετά ~> καλούμε την ToStack()

[X]Αν επιστρέψει true(τερματικό) ~> απλά βγάζουμε ένα στοιχείο/χαρακτήρα από την είσοδο.

    Σημειώση: Η διαδικασία αυτή θα γίνεται μέχρι η είσοδος να γίνει κενή
              ή να βγει άκυρο.


[X]--Function που εμφανίζει την συνάρτηση M(mt, t) όπως ο πίνακας στο Word.

    Σημείωση: Την καλούμε κάθε φορά πριν να εκτελέσουμε την ίδια την Function.


------------------------------------