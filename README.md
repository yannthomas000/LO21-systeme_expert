# LO21-systeme_expert
Un système expert est composé d’une base de connaissances, une base de faits et un moteur 
d’inférence. 
Dans ce projet, nous proposons de réaliser un système expert, dans lequel, les connaissances sont 
des propositions logiques pouvant avoir la valeur « vrai » ou « faux ». 
1. Définition des composantes d’un système expert - Une base de connaissances est une liste de règles.  - Une règle est composée de deux parties : -une partie prémisse contient des propositions reliées par l’opérateur logique « et »  - une partie conclusion contient une seule proposition. 
Exemple d’une règle :   A et B et C => D 
Dans cette règle, la prémisse est : A et B et C, la conclusion est D.  
Une règle se lit de la manière suivante : si la prémisse est vraie alors on déduit que la 
conclusion est vraie. 
On considère une règle comme une liste de propositions, dont le dernier élément est la 
conclusion de la règle. - Une base de faits est une liste de propositions considérées comme vraies. 
2. Questions 
1. Définir un type abstrait de données appelé Regle permettant de définir les règles d’une base 
de connaissances. Ecrire l’algorithme et le sous-programme C correspondant aux opérations 
suivantes : 
o Créer une règle vide, 
o Ajouter une proposition à la prémisse d’une règle, l’ajout se fait en queue 
o Créer la conclusion d’une règle 
o Tester si une proposition appartient à la prémisse d’une règle, de manière récursive 
o Supprimer une proposition de la prémisse d’une règle 
o Tester si la prémisse d’une règle est vide 
o Accéder à la proposition se trouvant en tête d’une prémisse  
o Accéder à la conclusion d’une règle 
2. Définir un type abstrait BC permettant de définir des Bases de Connaissances comme une 
liste de règles. Ecrire l’algorithme et le sous-programme C correspondant aux opérations 
suivantes :
