<%@ page pageEncoding="UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>Admin Panel</title>
</head>
<body>
		<%@ include file="menu.jsp" %>

		<form method="post" action="admin">
        <p>
            <label for="titre">Titre :<br> </label>
            <input type="text" name="titre" id="titre" />
        </p>
        <p>
         	<label for="description">Description :<br> </label>
			<textarea name="description" rows="5" cols="40" id="description"></textarea>
        </p>
        <input type="submit" value="Poster"/>
        
</body>
</html>