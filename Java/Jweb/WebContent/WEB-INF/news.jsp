<%@ page pageEncoding="UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>News</title>
</head>
<body>
	<%@ include file="menu.jsp" %>
	
	<ul>
        <c:forEach var="nouvelle" items="${ nouvelles }">
            <li> 
            	<p>
            		<c:out value="${ nouvelle.titre }" />
            		<br>
            		<c:out value="${ nouvelle.description }" />
            		<br>
            		auteur :
            		<c:out value="${ nouvelle.auteur }" />
            	</p>
            </li>
        </c:forEach>
    </ul>
</body>
</html>