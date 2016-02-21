<%@ page pageEncoding="UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>Produit</title>
</head>

<body>
	<%@ include file="menu.jsp" %>

	<h1>Nos produits</h1>

	<img alt="" src="C:/Users/Cyril/Pictures/maggi.jpg">
	
	<p>Véritable maggie de lorraine <br> Prix : 20€</p>
	
	<ul>
        <c:forEach var="coms" items="${ commentaires }">
            <li> 
            	<p>
            		<c:out value="${ coms.commentaire }" />
            		<br>
            		auteur :
            		<c:out value="${ coms.auteur }" />
            	</p>
            </li>
        </c:forEach>
    </ul>
    
	<c:if test="${ !empty sessionScope.user }">
	<form method="post" action="produit">
        <p>
            <label for="commentaire">Commentaire :<br> </label>
            <input type="text" name="commentaire" id="commentaire" />
        </p> 
    <input type="submit" value="Ajouter le commentaire" />
    </form>
	</c:if>
	<br>
	<br>
	
	<img alt="" src="C:/Users/Cyril/Pictures/Spaguetti.jpg">
	<p>Véritable spaghetti bolognese <br> Prix : 35€</p>
</body>
</html>