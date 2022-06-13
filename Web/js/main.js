function createIdentite (nom) {
    var typeNom = ['Nom', 'Prenom'];

    var contenu = "<form>"; // début du formulaire

    contenu += "<div class='form-group'>"; // début du groupe de champs

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
    contenu += "</form>";

    document.getElementById(nom).innerHTML = contenu;
}