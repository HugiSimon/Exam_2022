function createIdentite (nom) {
    var typeNom = ['Nom', 'Prenom'];
    var typeGenre = ['Homme', 'Femme'];

    var contenu = "<div class='form-group'>"; // début du groupe de champs

    contenu += "<label for='genre'>Genre : </label>"; // label pour le genre
    for(var i = 0; i < typeGenre.length ; i++) {
        contenu += "<label for='" + typeGenre[i] + "'>" + typeGenre[i] + "</label>";
        contenu += "<input type='radio' name='genre' value='" + typeGenre[i] + "'></input>";
    }

    contenu += "</div>"; 
    
    for(i=0; i < typeNom.length ;i++){ // pour le prenom et le nom
        contenu += "<div class='form-group'>";
        contenu += "<label for='" + typeNom[i] + "'>" + typeNom[i] + " : </label>";
        contenu += "<input type='text' id='" + typeNom[i] + "' placeholder='" + typeNom[i] + "'>";
        contenu += "</div>";
    }

    contenu += "<div class='form-group'>"; 

    contenu += "<label for='email'>Email : </label>"; // label pour l'email
    contenu += "<input type='email' id='email' placeholder='Email'>";

    contenu += "</div>";

    contenu += "<div class='form-group'>";
    
    contenu += "<label for='email2'>Confirmation Email : </label>"; // label pour la confirmation email
    contenu += "<input type='email' id='email2' placeholder='Confirmation Email'>";

    contenu += "</div>";

    contenu += "<div class='form-group'>";

    contenu += "<label for='date'>Date de naissance : </label>"; // label pour la date de naissance
    contenu += "<input type='date' id='date' placeholder='Date de naissance'>";

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

function createJeux (nom) {
    var contenu = "<div class='form-group'>"; // début du groupe de champs
    var typeJeux = ['Jeux de dés :', 'Jeux de cartes :', 'Jeux de plateau :', "Jeux d'adresse :", 'Jeux de connaisance :'];

    contenu += "<label for='jeux'>Vos types de jeux préférés : </label>"; // label pour le jeux
    for(var i = 0; i < typeJeux.length ; i++) {
        contenu += "<label for='" + typeJeux[i] + "'>" + typeJeux[i] + "</label>";
        contenu += "<input type='checkbox' name='" + typeJeux[i] + "' value='" + typeJeux[i] + "'></input>";
    }

    document.getElementById(nom).innerHTML = contenu;
}

function createAvis (nom) {
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
    contenu += "<textarea id='commentaire' rows='4' cols='50'></textarea>";
    contenu += "</div>";

    document.getElementById(nom).innerHTML = contenu;
}

function createBouton (nom) {
    var contenu = "<div class='form-group'>"; // début du groupe de champs
    contenu += "<button type='submit' id='envoyer'>Envoyer</button>";
    contenu += "<input type='reset' id='reset'>";
    contenu += "</div>";
    document.getElementById(nom).innerHTML = contenu;
}

function createAll (identite, jeux, avis, bouton) {
    createIdentite(identite);
    createJeux(jeux);
    createAvis(avis);
    createBouton(bouton);
}