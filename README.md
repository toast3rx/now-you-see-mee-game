### Nume: Latea Mihai Alexandru
### Grupa: 311CA

# **Now you see me - Tema 1**

### Descriere:

* In cod, structurile ```deck``` si ```playing_set``` sunt implementate la fel\
prin liste dublu inlanuite dar sunt denumite diferit pentru a fi mai usor de\
citit codul si urmat logica acestuia.

* Tema simuleaza un joc de carti bazat pe filmul "Now you see me"\
in care utilizatorul poate efectua mai multe operatiuni asupra\
mai multor pachete de carti:
    * Comanda _ADD\_DECK_
      * Creeaza un nou pachet cu un numar dat de carti cititite de la tastatura;
    * Comanda _DEL\_DECK_:
      * Sterge un pachet de carti de pe o anumita pozitie;
    * Comanda _DEL\_CARD_:
      * Sterge o carte de pe o anumita pozitie dintr-un pachet de la un index;
    * Comanda _ADD\_CARDS_:
      * Adauga un numar dat de carti la un pachet deja existent;
    * Comanda _DECK\_NUMBER_:
      * Intoarce numarul de pachete de joc existente;
    * Comanda _DECK\_LEN:
      * Intoarce numarul de carti dintr-un anumit pachet;
    * Comanda _SHUFFLE\_DECK_:
      * Inverseaza prima jumatate a pachetului cu cea de a doua;
    * Comanda _MERGE\_DECKS_ : 
      * Combina doua pachete din setul de joc;
    * Comanda _SPLIT\_DECK_:
      * Imparte un pachet de la o anumita pozitie in doua pachete la indexul\
       specificat
    * Comanda _REVERSE\_DECK_:
      * Inverseaza ordinea cartilor dintr-un pachet;
    * Comanda _SHOW\_DECK_:
      * Afiseaza cartile dintr-un anumit pachet;
    * Comanda _SHOW\_ALL_:
      * Afiseaza continutul fiecarui pachet de carti;
    * Comanda _EXIT_:
      * Incheie programul si elibereaza memoria alocata;

## Comentarii asupra temei:

* Cred ca mai poate fi imbunatatita tema cand vine vorba de\
prelucrarea erorilor, in special cand este trimisa valoarea _NULL_\
ca paramaetru unei functii in loc de o lista.
* Din aceasta tema am invatat sa folosesc mai bine listele inlantuite generice.
* Am considerat ca implementarea listei provine dintr-o biblioteca\
si am construit functii pentru a incapsula comportamentul celor deja\
implementate, modelandu-le dupa nevoile aplicatiei.