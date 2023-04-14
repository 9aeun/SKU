<%@ page contentType="text/html; charset=utf-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%
	String sessionId = (String) session.getAttribute("sessionId");
%>
<link rel="stylesheet" href="./resources/css/bootstrap.min.css" />
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Hi+Melody&family=Nanum+Gothic:wght@700&family=Poor+Story&display=swap" rel="stylesheet">
<nav class="navbar navbar-expand navbar-dark bg-white text-muted" style="font-family: 'Nanum Gothic', sans-serif;">
	<div class="container">
		<div>
			<ul id="nav" class="nav justify-content-around bg-white">
				<li class="nav-item"><a class="nav-link" href="./products.jsp">전체상품</a></li>
				<li class="nav-item"><a class="nav-link" href="./souce.jsp">| 저칼로리 소스</a></li>
				<li class="nav-item"><a class="nav-link" href="./rice.jsp">| 다이어트 리조또 & 죽</a></li>
				<li class="nav-item"><a class="nav-link" href="./noodle.jsp">| 다이어트 면</a></li>
				<li class="nav-item"><a class="nav-link" href="<c:url value="/BoardListAction.do?pageNum=1"/>">| ☆다이어트 꿀팁 공유 게시판☆</a></li>
			</ul>
		</div>
	</div>
</nav>
