<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<nav>
<ul style="text-align:center;">
	<li style="display:inline; padding-right: 35px;"><a href="/Jweb/acceuil">Acceuil</a></li>
	<li style="display:inline; padding-right: 35px;"><a href="/Jweb/news">News</a></li>
	<li style="display:inline; padding-right: 35px;"><a href="/Jweb/produit">Produit</a></li>
	
	<c:if test="${ empty sessionScope.user }">
	<li style="display:inline; padding-right: 35px;"><a href="/Jweb/connect">Connexion</a></li>
	</c:if>
	
	<c:if test="${ !empty sessionScope.user }">
	<li style="display:inline; padding-right: 35px;"><a href="/Jweb/Deconnect">Deconnexion</a></li>
	</c:if>
	
	<c:if test="${ sessionScope.user.admin }">
		<li style="display:inline; padding-right: 35px;"><a href="/Jweb/admin">Admin</a></li>
	</c:if>
</ul>
</nav>