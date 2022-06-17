function createTablo () {
    var reponse = document.location.search; // récupération de la partie après ? dans l'url
    reponse = reponse.substring(1); // on enlève le premier caractère qui est ?
    reponse = reponse.split("&"); // on sépare les différentes variables
    for (var i = 0; i < reponse.length; i++) { // on parcourt les paramètres
        for (var j = 0; j < reponse[i].length; j++) { // on parcourt les caractères
            reponse[i] = reponse[i].replace("+", " "); // on remplace tout les caractères indésirables 
            reponse[i] = reponse[i].replace("%40", "@");
            reponse[i] = reponse[i].replace("%27", "'");
            reponse[i] = reponse[i].replace("%C3%A8", "è");
            reponse[i] = reponse[i].replace("%C3%B4", "ô");
            reponse[i] = reponse[i].replace("%C3%A0", "à");
            reponse[i] = reponse[i].replace("%C3%A9", "é");
            reponse[i] = reponse[i].replace("%C3%A2", "â");
            reponse[i] = reponse[i].replace("%C3%A0", "à");
            reponse[i] = reponse[i].replace("%C3%A7", "ç");
            reponse[i] = reponse[i].replace("%2C", ",");
            reponse[i] = reponse[i].replace("%3A", ":");
            reponse[i] = reponse[i].replace("%3F", "?");
            reponse[i] = reponse[i].replace("%2F", "/");
            reponse[i] = reponse[i].replace("%2B", "+");
            reponse[i] = reponse[i].replace("%2D", "-");
            reponse[i] = reponse[i].replace("%2E", ".");
            reponse[i] = reponse[i].replace("%21", "!");
        }
    }

    var contenu = "<table>"; // on crée la table
    contenu += "<thead><tr><th>Nom</th><th>Réponse/Checked/Avis</th></tr></thead>"; // le thead

    contenu += "<tbody>";
    for (var i = 0; i < reponse.length; i++) {
        var donnees = reponse[i].split("="); // on sépare les données
        if (donnees[0] != donnees[1]) { // si c'est la même réponse on affiche Checked
            contenu += "<tr><td>" + donnees[0] + "</td><td>" + donnees[1] + "</td></tr>";
        }
        else {
            contenu += "<tr><td>" + donnees[0] + "</td><td>Checked</td></tr>";
        }
    }
    contenu += "</tbody>";
    contenu += "</table>";

    document.getElementById("main").innerHTML = contenu;
}