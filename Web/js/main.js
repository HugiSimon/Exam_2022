function createIdentite (nom) { // créé le formulaire d'identité
    var typeNom = ['Nom', 'Prenom'];
    var typeGenre = ['Homme', 'Femme'];

    var contenu = "<div class='form-group'>"; // début du groupe de champs

    contenu += "<label for='genre'>Genre : </label>"; // label pour le genre
    for(var i = 0; i < typeGenre.length ; i++) {
        contenu += "<label for='" + typeGenre[i] + "'>" + typeGenre[i] + "</label>";
        contenu += "<input type='radio' name='genre' value='" + typeGenre[i] + "' class='red'></input>";
    }

    contenu += "</div>"; 
    
    for(i=0; i < typeNom.length ;i++){ // pour le prenom et le nom
        contenu += "<div class='form-group'>";
        contenu += "<label for='" + typeNom[i] + "'>" + typeNom[i] + " : </label>";
        contenu += "<input type='text' class='red' id='" + typeNom[i] + "' placeholder='" + typeNom[i] + "'>";
        contenu += "</div>";
    }

    contenu += "<div class='form-group'>"; 

    contenu += "<label for='email'>Email : </label>"; // label pour l'email
    contenu += "<input type='email' class='red' id='email' placeholder='Email'>";

    contenu += "</div>";

    contenu += "<div class='form-group'>";
    
    contenu += "<label for='email2'>Confirmation Email : </label>"; // label pour la confirmation email
    contenu += "<input type='email' class='red' id='email2' placeholder='Confirmation Email'>";

    contenu += "</div>";

    contenu += "<div class='form-group'>";

    contenu += "<label for='date'>Date de naissance : </label>"; // label pour la date de naissance
    contenu += "<input type='date' class='red' id='date' placeholder='Date de naissance'>";

    contenu += "</div>";

    contenu += "<div class='form-group'>";

    contenu += "<label for='adresse'>Adresse : </label>"; // label pour l'adresse
    contenu += "<input type='text' id='adresse' placeholder='Adresse'>";
    contenu += "<label for='codePostale'> Code Postal : </label>"; // label pour le code postal
    contenu += "<input type='text' id='codePostale' placeholder='Code Postal'>";
    contenu += "<label for='ville'> Ville : </label>"; // label pour la ville
    contenu += "<input type='text' id='ville' placeholder='Ville'>";

    contenu += "</div>";

    contenu += "<div class='form-group'>";

    contenu += "<label for='telephone'>Téléphone : </label>"; // label pour le téléphone
    contenu += "<input type='text' id='telephone' placeholder='Téléphone'>";

    contenu += "</div>";

    document.getElementById(nom).innerHTML = contenu;
}

function createJeux (nom) { // créé le formulaire de jeux
    var contenu = "<div class='form-group'>"; // début du groupe de champs
    var typeJeux = ['Jeux de dés :', 'Jeux de cartes :', 'Jeux de plateau :', "Jeux d adresse :", 'Jeux de connaisance :'];

    contenu += "<label for='jeux'>Vos types de jeux préférés : </label>"; // label pour le jeux
    for(var i = 0; i < typeJeux.length ; i++) {
        contenu += "<div class='typeJeu' id='typeNumero" + i +"'>";
        contenu += "<label for='" + typeJeux[i] + "'>" + typeJeux[i] + "</label>";
        contenu += "<input type='checkbox' class='TypeJeuPref' name='" + typeJeux[i] + "' value='" + typeJeux[i] + "' onchange='selectJeu(" + '"' + "typeNumero" + i + '"' + ")'></input>";
        contenu += "</div>";
    }

    document.getElementById(nom).innerHTML = contenu;
}

function createAvis (nom) { // créé le formulaire d'avis
    var TypeDeJeux = ['Monopoly', 'Uno', 'Jenga', 'Limite Limite'];
    //Choix d'un jeu pour lui donner un avis
    var contenu = "<div class='form-group'>"; // début du groupe de champs
    contenu += "<label for='avis'>Votre avis sur le jeu : </label>"; // label pour le jeux
    contenu += "<select id='avis'>";
    for(var i = 0; i < TypeDeJeux.length ; i++) {
        contenu += "<option value='" + TypeDeJeux[i] + "'>" + TypeDeJeux[i] + "</option>";
    }
    contenu += "</select>";
    contenu += "</div>";

    //Choix de la note pour le jeu
    contenu += "<div class='form-group'>"; // début du groupe de champs
    contenu += "<label for='note'>Votre note sur le jeu : </label>"; // label pour le jeux
    contenu += "<select id='note'>";
    for(var i = 1; i < 6 ; i++) {
        contenu += "<option value='" + i + "'>" + i + "</option>";
    }
    contenu += "</select>";
    contenu += "</div>";

    //Commentaire sur le jeu de 200 caractère (optionel)
    contenu += "<div class='form-group'>"; // début du groupe de champs
    contenu += "<label for='commentaire'>Votre commentaire sur le jeu : </label>"; // label pour le jeux
    contenu += "<textarea class='red' id='commentaire' rows='4' cols='50'></textarea>";
    contenu += "</div>";

    document.getElementById(nom).innerHTML = contenu;
}

function createBouton (nom) { // créé le bouton de validation
    var contenu = "<div class='form-group'>"; // début du groupe de champs
    contenu += "<button type='button' id='envoyer' value='envoyer' onclick='checkRequired()'>Envoyer</button>";
    contenu += "<input type='reset' id='reset'>";
    contenu += "</div>";
    document.getElementById(nom).innerHTML = contenu;
}

function createAll (identite, jeux, avis, bouton) { // créé tout le formulaire
    createIdentite(identite);
    createJeux(jeux);
    createAvis(avis);
    createBouton(bouton);
}

function selectJeu (nom) { // liste a choix multilple de jeux à partir des types de jeux préférés
    var contenu = document.getElementById(nom).innerHTML;
    var typeJeux = [['Jeux de dés :', 'Rummikub', 'Story Cubes', 'Wazabi'], ['Jeux de cartes :', 'Uno', 'Solitaire', 'Tarot', 'Mille Borne'], ['Jeux de plateau :', 'Monopoly', 'Petits Chevaux', "Jeu de l'oie"], ["Jeux d adresse :", 'Mikado', "Jenga", "Twister"], ['Jeux de connaisance :', "Trivial Poursuit", "Time's Up"]];
    var numeroJeu = parseInt(nom.split("typeNumero")[1]) // récupère le numéro du type de jeux pour avoir le bon tableau
    if (document.getElementsByName(contenu.split('"')[1])[0].checked) { // si le type de jeux est coché ou non
        for (var i = 1; i < typeJeux[numeroJeu].length; i++) {
            contenu += "<div class='typeAimeJeu'>";
            contenu += "<label for='" + typeJeux[numeroJeu][i] + "'>" + typeJeux[numeroJeu][i] + "</label>";
            contenu += "<input type='checkbox' class='TypeJeuPref' name='" + typeJeux[numeroJeu][i] + "' value='" + typeJeux[numeroJeu][i] + "'></input>";
            contenu += "</div>";
        }
        document.getElementById(nom).innerHTML = contenu;
        document.getElementsByName(contenu.split('"')[1])[0].checked = true; // coche le type de jeux car s'enlève tout seul
    }
    else {
        contenu = contenu.split("<div")[0]; // récupère le code avant qu'il était coché
        document.getElementById(nom).innerHTML = contenu;
    }
}   

function checkRequired() { // vérifie que tous les champs obligatoires sont remplis
    var compteur = 0; // compte le nombre de champ requis manquant

    var required = document.getElementsByClassName('red'); 
    for(var i = 0; i < required.length ; i++) { // parcours tous les champs requis
        if(required[i].value == "") {
            required[i].style.border = "2px solid red";
            compteur++;
        }
    }

    if (document.getElementById('email').value != document.getElementById('email2').value) { // vérifie que les emails sont identiques
        document.getElementById('email').style.border = "2px solid red";
        document.getElementById('email2').style.border = "2px solid red";
        compteur++;
    }

    var radio = document.getElementsByName('genre');
    var j = 0;
    for(var i = 0; i < radio.length ; i++) { // parcours tous les champs radio genre
        if(radio[i].checked) {
            j++;
        }
    }
    if(j == 0) { // vérifie que le genre est choisi
        for (var i = 0; i < radio.length; i++) { 
            radio[i].style.boxShadow = "0 0 0 2px red"; 
        }
        compteur++;
    }

    var typedejeu = document.getElementsByClassName('TypeJeuPref');
    var j = 0;
    var k = 0;
    for(var i = 0; i < typedejeu.length ; i++) { // parcours tous les champs checkbox type de jeu
        if(typedejeu[i].checked) {
            j++;
        }
    }
    if(j == 0) { // vérifie que le type de jeu est choisi
        for (var i = 0; i < typedejeu.length ; i++) {
            typedejeu[i].style.boxShadow = "0 0 0 2px red";
        }
        compteur++;
    }
    else{ // le type jeu est choisi, mais vérifier les jeux aimés
        for (var i = 0; i < document.getElementsByClassName("typeAimeJeu").length; i++) {
            if(document.getElementsByClassName("typeAimeJeu")[i].getElementsByTagName("input")[0].checked) { // vérifie que le les jeux aimés sont choisis
                k++;
            }
        }
    }
    if(k == 0) { // vérifie que le les jeux aimés sont choisis
        for (var i = 0; i < document.getElementsByClassName("typeAimeJeu").length; i++) {
            document.getElementsByClassName("typeAimeJeu")[i].getElementsByTagName("input")[0].style.boxShadow = "0 0 0 2px red";
        }
        compteur++;
    }

    if(compteur == 0) { // si tous les champs sont remplis
        return true;
    }
    else {
        return false;
    }

}