<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@page import="java.util.Date" %>
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
<link rel="stylesheet" href="./resources/css/bootstrap.min.css">
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Hi+Melody&family=Nanum+Gothic:wght@700&family=Poor+Story&display=swap" rel="stylesheet">
<title>전체 상품</title>
</head>
<body>
	<jsp:include page="/menu.jsp" />
	<jsp:include page="/menu2.jsp" />
	<jsp:include page="/menu3.jsp" />
	<div class = "container" style="font-family: 'Nanum Gothic', sans-serif;">
		<div class="text-center">
			<br>
			<br>
			<br>
			<div class="container" style="text-align : center;">
				<img src="./images/bg.png "style ="width:300" class="center-block">
			</div>
			<h1>
				<%="\n\n\n먹으면서 건강하게 빼자!" %>
			</h1>
			
			<h2>
				<%="\n\n\n가은'S DIAT 쇼핑몰에 오신 것을 환영합니다."%>
			</h2>
			<br><br>
			<%
				response.setIntHeader("Refresh", 5);
				Date day=new java.util.Date();
				String am_pm;
				int hour = day.getHours();
				int minute = day.getMinutes();
				int second = day.getSeconds();
				if(hour/12==0){
					am_pm="AM";
				}else{
					am_pm="PM";
					hour=hour-12;
				}
				String CT=hour+":"+minute+":"+second+" "+am_pm;
				out.println("현재 접속 시각: "+CT+"\n");
			%>
			<br>
			<br>
			<br>
		</div>
		<hr>
		<%@ include file="footer.jsp" %>
	</div>
</body>
</html>
