<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@ page import = "java.sql.*" %>
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
<link rel="stylesheet" href="./resources/css/bootstrap.min.css">
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Hi+Melody&family=Nanum+Gothic:wght@700&family=Poor+Story&display=swap" rel="stylesheet">
<title>상품 상세 정보</title>
<script type="text/javascript">
	function addToCart(){
		if(confirm("상품을 장바구니에 추가하시겠습니까?")){
			document.addForm.submit();
		} else{
			document.addForm.reset();
		}
	}
</script>
</head>
<body>
	<jsp:include page="/menu.jsp" />
	<jsp:include page="/menu2.jsp" />
	<jsp:include page="/menu3.jsp" />
	<br><br>
	<div class="container" style="font-family: 'Hi Melody', cursive;">
		<div class="row">
			<%@ include file="dbconn.jsp"%>
			<%
				String productId = request.getParameter("id");

				PreparedStatement pstmt = null;
				ResultSet rs = null;
	
				String sql = "select * from product where p_id = ?";
				pstmt = conn.prepareStatement(sql);
				pstmt.setString(1, productId);
				rs = pstmt.executeQuery();
				if (rs.next()) {
			%>
			<div class="col-md-5">
				<img src="./images/<%=rs.getString("p_fileName")%>"style ="width:100%">
			</div>
			<div class="col-md-6">
				<h3><%= rs.getString("p_name")%></h3>
				<p><%=rs.getString("p_description")%>
				<p><b>상품 코드 : </b><span class="badge badge-danger">
				   <%=rs.getString("p_id")%></span>
				<p> <b>제조사</b> : <%=rs.getString("p_manufacturer")%>
				<p> <b>분류</b> : <%=rs.getString("p_category")%>
				<p> <b>칼로리</b> : <%=rs.getString("p_calorie")%>kcal
				<p> <b>양 </b> : <%=rs.getString("p_volume")%>g
				<h4><%=rs.getString("p_UnitPrice")%>원</h4>
				<p> <form name="addForm" action="./addCart.jsp?id=<%=rs.getString("p_id")%>" method="post">
					<a href="#" class="btn btn-info" onclick="addToCart()"> 상품 주문 &raquo;</a>
					<a href="./cart.jsp" class="btn btn-warning"> 장바구니 &raquo;</a>
					<a href="./products.jsp" class="btn btn-secondary"> 상품 목록 &raquo;</a>
				</form>
			</div>
			<%
				}		

				if (rs!=null)
					rs.close();
				if (pstmt!=null)
					pstmt.close();
				if(conn!=null)
					conn.close();
			%>
		</div>
	</div>
	<jsp:include page="footer.jsp" />
</body>
</html>
