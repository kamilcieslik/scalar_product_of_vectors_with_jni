# Rozbudowa wybranej aplikacji Java o funkcje zaimplementowane w kodzie natywnym. 
Napisz program z wykorzystaniem JNI, w którym zostanie wykorzystana klasa posiadająca
metody natywne służące do obliczania iloczynu skalarnego dwóch wektorów.
Schemat implementacji tej klasy powinien być taki, jak pokazano poniżej.
W trakcie implementacji należy zwrócić uwagę na właściwą alokację i zwalnianie
pamięci po stronie kodu natywnego oraz na zgodność bitową JVM oraz bibliteki
ładowanej dynamicznie (32/64 bit). Do realizacji zadania można wykorzystać
dowolne kompilatory języka C/C++ (niezbędne do wygenerowania biblioteki
ładowanej dynamicznie). 