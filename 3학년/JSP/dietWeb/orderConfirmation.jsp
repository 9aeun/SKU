<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@ page import="java.util.ArrayList" %>
<%@ page import = "java.net.URLDecoder" %>
<%@ page import = "dto.Product" %>
<%@ page import = "dao.ProductRepository" %>
<%
	request.setCharacterEncoding("UTF-8");
	
String shipping_cartId="";
String shipping_name="";
String shipping_shippingDate="";
String shipping_country="";
String shipping_zipcode="";
String shipping_address="";
String shipping_detailAddress="";
String shipping_references="";

Cookie[] cookies = request.getCookies();

if(cookies != null){
	for(int i=0; i<cookies.length; i++){
		Cookie thisCookie = cookies[i];
		String n = thisCookie.getName();
		if(n.equals("Shipping_cartId"))
			shipping_cartId = URLDecoder.decode((thisCookie.getValue()), "utf-8");
		if(n.equals("Shipping_name"))
			shipping_name = URLDecoder.decode((thisCookie.getValue()), "utf-8");
		if(n.equals("Shipping_shippingDate"))
			shipping_shippingDate = URLDecoder.decode((thisCookie.getValue()), "utf-8");
		if(n.equals("Shipping_zipcode"))
			shipping_zipcode = URLDecoder.decode((thisCookie.getValue()), "utf-8");
		if(n.equals("Shipping_country"))
			shipping_country = URLDecoder.decode((thisCookie.getValue()), "utf-8");
		if(n.equals("Shipping_address"))
			shipping_address = URLDecoder.decode((thisCookie.getValue()), "utf-8");
		if(n.equals("Shipping_detailAddress"))
			shipping_detailAddress = URLDecoder.decode((thisCookie.getValue()), "utf-8");
		if(n.equals("Shipping_references"))
			shipping_references = URLDecoder.decode((thisCookie.getValue()), "utf-8");
		}
	}
%>
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
<link rel="stylesheet" href="./resources/css/bootstrap.min.css">
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Hi+Melody&family=Nanum+Gothic:wght@700&family=Poor+Story&display=swap" rel="stylesheet">
<title>주문 정보</title>
</head>
<body>
	<jsp:include page="menu.jsp" />
	<div class="jumbotron bg-white">
		<div class="container" style="text-align : center;">
			<img src="./images/logo.png "style ="width:400px" class="center-block">
			<br><br><br>
			<h1 class="display-3" style="font-family: 'Hi Melody', cursive;">주문 정보</h1>
		</div>
		<br><br><br>
		<jsp:include page="/menu3.jsp" />
	</div>
	<div class="container col-8 alert alert-info" style="font-family: 'Poor Story', cursive;">
		<div class="text-center">
			<h1>영수증</h1>
		</div>
		<div class="row justify-content-between">
			<div class="col-8" align="left">
				<strong>배송 주소</strong> <br> 성명 : <% out.println(shipping_name); %>	<br>
				 우편번호 : <%out.println(shipping_zipcode); %>	<br>
				 주소 : <% out.println(shipping_address); %><% out.println(shipping_detailAddress); %><% out.println(shipping_references); %>(<%out.println(shipping_country); %>) <br>
			</div>
			<div class="col-4" align="right">
				<p> <em>배송일: <%out.println(shipping_shippingDate); %></em>
			</div>
		</div>
		<div>
			<table class="table table-hover" style="background-color:white;">
			<tr>
				<th class="text-center">상품</th>
				<th class="text-center">#</th>
				<th class="text-center">가격</th>
				<th class="text-center">kcal</th>
			</tr>
			<%
				int sum=0;
				double c_sum=0;	//칼로리 계산을 위해
				ArrayList<Product> cartList = (ArrayList<Product>) session.getAttribute("cartlist");
				if(cartList== null)
					cartList = new ArrayList<Product>();
				for(int i=0; i<cartList.size(); i++){ //상품 리스트 하나씩 출력하기
					Product product = cartList.get(i);
					int total = product.getUnitPrice() * product.getQuantity();
					double c_total = product.getCalorie() * product.getQuantity();
					sum=sum+total;
					c_sum+=c_total;
			%>
			<tr>
				<td class="text-center"><em><%=product.getPname() %></em></td>
				<td class="text-center"><%=product.getUnitPrice() %>원</td>
				<td class="text-center"><%=total %></td>
				<td class="text-center"><%=c_total %>kcal</td>
			</tr>
			<%
			}
			%>
			<tr>
				<td></td>
				<td></td>
				<td class="text-right"><strong>총액: </strong></td>
				<td class="text-center text-danger"><strong><%=sum %>원</strong></td>
				<td class="text-right"><strong>총칼로리: </strong></td>
				<td class="text-center text-danger"><strong><%=c_sum %> kcal</strong></td>
			</tr>
			</table>
			
			<a href = "./shippingInfo.jsp?cartId=<%=shipping_cartId %>" class="btn btn-secondary" role="button"> 이전 </a>
			<a href="./thankCustomer.jsp" class="btn btn-warning" role="button"> 주문 완료 </a>
			<a href="./checkOutCancelled.jsp" class="btn btn-secondary" role="button"> 취소 </a>
		</div>
	</div>
	
</body>
</html>
