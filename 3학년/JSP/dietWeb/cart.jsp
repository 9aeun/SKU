<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@ page import = "java.util.ArrayList" %>
<%@ page import = "dto.Product" %>
<%@ page import = "dao.ProductRepository" %>
<!DOCTYPE html>
<html>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Hi+Melody&family=Nanum+Gothic:wght@700&family=Poor+Story&display=swap" rel="stylesheet">
<%
	String cartId = session.getId();
%>
<head>
<meta charset="EUC-KR">
<title>장바구니</title>
</head>
<body>
	<jsp:include page="menu.jsp" />
	<div class="jumbotron bg-white">
		<div class="container" style="text-align : center;">
			<img src="./images/logo.png "style ="width:400px" class="center-block">
			<br><br><br>
			<h1 class="display-3" style="font-family: 'Hi Melody', cursive;">장바구니</h1>
		</div>
		<br><br><br>
		<jsp:include page="/menu3.jsp" />
	</div>
		<div class="container">
			<div class="row">
				<table width="100%">
					<tr>
						<td align="left"><a href="./deleteCart.jsp?cartId=<%=cartId %>" class="btn btn-danger">삭제하기</a></td>
						<td align="right"><a href="./shippingInfo.jsp?cartId<%=cartId %>" class="btn btn-success">주문하기</a></td>
					</tr>
				</table>
			</div>
			<div style="padding-top: 50px">
				<table class="table table-hover">
					<tr>
						<th>상품</th>
						<th>비고</th>
						<th>수량</th>
						<th>소계</th>
						<th>비고</th>
					</tr>
					<%
						int sum=0;
						ArrayList<Product> cartList = (ArrayList<Product>)session.getAttribute("cartlist");
						if(cartList == null)
							cartList = new ArrayList<Product>();
						for(int i=0; i<cartList.size(); i++){ //상품 리스트 하나씩 출력하기
							Product product = cartList.get(i);
							int total = product.getUnitPrice() * product.getQuantity();
							sum=sum+total;
					%>
					<tr>
						<td><%=product.getProductId() %>-<%=product.getPname() %></td>
						<td><%=product.getUnitPrice() %></td>
						<td><%=product.getQuantity() %></td>
						<td><%=total %></td>
						<td><a href = "./removeCart.jsp?id=<%=product.getProductId() %>" class="badge badge-danger">삭제</a></td>
					</tr>
					<%
						}					
					%>
					<tr>
						<th></th>
						<th></th>
						<th>총액</th>
						<th><%=sum %></th>
						<th></th>
					</tr>
				</table>
				<a href = "./products.jsp" class="btn btn-secondary">&laquo; 쇼핑 계속하기</a>
		</div>
		<hr>
	</div>
	<jsp:include page = "footer.jsp" />
</body>
</html>
