function createIdentite (nom) {
    var typeNom = ['Nom', 'Prenom'];

    var contenu = "<div class='form-group'>"; // début du groupe de champs

    contenu += "<label for='genre'>Genre : </label>"; // label pour le genre
    contenu += '<label for="Homme">Homme</label>'; // label pour l'homme
    contenu += '<input type="radio" name="genre" value="Homme" id="Homme" checked>';
    contenu += '<label for="Femme"> Femme</label>'; // label pour la femme
    contenu += '<input type="radio" name="genre" value="Femme" id="Femme">';

    contenu += "</div>"; 
    
    for(i=0; i < 2 ;i++){ // pour le prenom et le nom
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

    contenu += "<label for='jeux'>Vos types de jeux préférés : </label>"; // label pour le jeux
    contenu += "<div class='form-check'>";
    contenu += "<input type='checkbox' id='jeux' value='Jeux de dés'>Jeux de dés";
    contenu += "</div>";
    contenu += "<div class='form-check'>";
    contenu += "<input type='checkbox' id='jeux' value='Jeux de cartes'>Jeux de cartes";
    contenu += "</div>";
    contenu += "<div class='form-check'>";
    contenu += "<input type='checkbox' id='jeux' value='Jeux de plateau'>Jeux de plateau";
    contenu += "</div>";
    contenu += "<div class='form-check'>";
    contenu += "<input type='checkbox' id='jeux' value='Jeux d\'adress'>Jeux d\'adress";
    contenu += "</div>";
    contenu += "<div class='form-check'>";
    contenu += "<input type='checkbox' id='jeux' value='Jeux de conaissance'>Jeux de conaissance";
    contenu += "</div>";

    document.getElementById(nom).innerHTML = contenu;
}

function createAvis (nom) {
    //Choix d'un jeu pour lui donner un avis
    var contenu = "<div class='form-group'>"; // début du groupe de champs
    contenu += "<label for='avis'>Votre avis sur le jeu : </label>"; // label pour le jeux
    contenu += "<select id='avis'>";
    contenu += "<option value='Monopoly'>Monopoly</option>";
    contenu += "<option value='Uno'>Uno</option>";
    contenu += "<option value='Jenga'>Jenga</option>";
    contenu += "<option value='Limite Limite'>Limite Limite</option>";
    contenu += "</select>";
    contenu += "</div>";

    //Choix de la note pour le jeu
    contenu += "<div class='form-group'>"; // début du groupe de champs
    contenu += "<label for='note'>Votre note sur le jeu : </label>"; // label pour le jeux
    contenu += "<select id='note'>";
    contenu += "<option value='1'>1</option>";
    contenu += "<option value='2'>2</option>";
    contenu += "<option value='3'>3</option>";
    contenu += "<option value='4'>4</option>";
    contenu += "<option value='5'>5</option>";
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