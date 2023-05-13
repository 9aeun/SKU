<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@ page import="java.net.URLDecoder" %>
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
<link rel="stylesheet" href="./resources/css/bootstrap.min.css">
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Hi+Melody&family=Nanum+Gothic:wght@700&family=Poor+Story&display=swap" rel="stylesheet">
<title>주문 완료</title>
</head>
<body>
	<%
		String shipping_cartId="";
		String shipping_shippingDate="";
		
		Cookie[] cookies = request.getCookies();
		if(cookies != null){
			for(int i=0; i<cookies.length; i++){
				Cookie thisCookie = cookies[i];
				String n = thisCookie.getName();
				if(n.equals("Shipping_cartId"))
					shipping_cartId = URLDecoder.decode((thisCookie.getValue()), "utf-8");
				if(n.equals("Shipping_shippingDate"))
					shipping_shippingDate = URLDecoder.decode((thisCookie.getValue()), "utf-8");
			}
		}
	%>
	<jsp:include page="/menu.jsp" />
	<div class="jumbotron bg-white">
		<div class="container" style="text-align : center;">
			<img src="./images/logo.png "style ="width:400px" class="center-block">
			<br><br><br>
			<h1 class="display-3" style="font-family: 'Hi Melody', cursive;">주문 완료</h1>
		</div>
		<br><br><br>
		<jsp:include page="/menu3.jsp" />
	</div>
	<div class="container">
		<h2 class="alert alert-white">주문해주셔서 감사합니다. *^^*</h2>
		<br><br>
		<p> 주문은 <% out.println(shipping_shippingDate); %>에 배송될 예정입니다!
		<p> 주문번호 : <%out.println(shipping_cartId); %>
	</div>
	<div class="container">
		<p> <a href = "./products.jsp" class="btn btn-secondary">&laquo; 상품 목록</a>
	</div>
</body>
</html>
<%
	session.invalidate();
	
	for(int i=0; i<cookies.length; i++){
		Cookie thisCookie = cookies[i];
		String n = thisCookie.getName();
		if(n.equals("Shipping_cartId"))
			thisCookie.setMaxAge(0);
		if(n.equals("Shipping_name"))
			thisCookie.setMaxAge(0);
		if(n.equals("Shipping_shippingDate"))
			thisCookie.setMaxAge(0);
		if(n.equals("Shipping_country"))
			thisCookie.setMaxAge(0);
		if(n.equals("Shipping_zipCode"))
			thisCookie.setMaxAge(0);
		if(n.equals("Shipping_addressName"))
			thisCookie.setMaxAge(0);
		
		response.addCookie(thisCookie);
	}
%>
