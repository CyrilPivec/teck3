<%@ page pageEncoding="UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>Connection</title>
</head>
<body>
	<%@ include file="menu.jsp" %>
	<c:if test="${ !empty sessionScope.user }">
        <p>Vous êtes connecté ${ sessionScope.user.prenom } !</p>
    </c:if>
   <c:if test="${ !empty sessionScope.bad }">
        <p>Mauvais compte saisie !</p>
    </c:if>
    
	<form method="post" action="Connect" style="text-align:center;">
        <p>
            <label for="email">email :<br> </label>
            <input type="text" name="mail" id="mail" />
        </p>
        <p>
            <label for="mdp">Mot de passe :<br> </label>
            <input type="password" name="mdp" id="mdp" />
        </p>
        
        <input type="submit" />
        <br>
        <br>
        <a href="create">Créer un compte</a>
    </form>
    <p>Membre inscrit : </p>
    <ul>
    	<c:forEach var="utilisateur" items="${ utilisateurs }">
    		<li><c:out value="${ utilisateur.prenom }" /> <c:out value="${ utilisateur.nom }" /></li>
    	</c:forEach>
    </ul>
</body>
</html>