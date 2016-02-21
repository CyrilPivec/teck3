<%@ page pageEncoding="UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>Créer un compte</title>
</head>
<body>
		<%@ include file="menu.jsp" %>

		<form method="post" action="Create">
        <p>
            <label for="nom">Nom :<br> </label>
            <input type="text" name="nom" id="nom" />
        </p>
        <p>
            <label for="prenom">Prenom :<br> </label>
            <input type="text" name="prenom" id="prenom" />
        </p>
        <p>
            <label for="mdp">Mot de passe :<br> </label>
            <input type="password" name="mdp" id="mdp" />
        </p>
        <p>
            <label for="mail">Email :<br> </label>
            <input type="email" name="mail" id="mail" />
        </p>
        
        <p>
            <label for="newsLetter">Newsletter : </label>
            <input type="checkbox" name="newsLetter" id="newsLetter" checked="check" />
        </p>
        <input type="submit" value="Créer" />
</body>
</html>