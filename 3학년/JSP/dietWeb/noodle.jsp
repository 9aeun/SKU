<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@ page import = "java.sql.*" %>
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
<title>곤약면</title>
</head>
<body>
	<jsp:include page="/menu.jsp" />
	<jsp:include page="/menu2.jsp" />
	<jsp:include page="/menu3.jsp" />
	<div class="container">
		<div class="row" align="center"  style="font-family: 'Hi Melody', cursive;">
			<%@ include file ="dbconn.jsp" %>
			<%
				PreparedStatement pstmt = null;
				ResultSet rs = null;
				String sql = "select * from product" ;
				pstmt = conn.prepareStatement(sql);
				rs = pstmt.executeQuery();
				while ( rs.next()) {
					if(rs.getString("p_category").equals("면")){
			%>
			<div class = "col-md-4">
				<img src="./images/<%=rs.getString("p_fileName")%>"style ="width:100%">
				<h4><%= rs.getString("p_name")%></h4>
				<p><%=rs.getString("p_description")%>
				<p><%=rs.getString("p_UnitPrice")%>원
				<p><a href= "./product.jsp?id=<%= rs.getString("p_id")%>" 
					class = "btn btn-outline-warning" role = "button">상세 정보 
					&raquo;</a></p>
			</div>
			<%
					}
				}		

				if (rs!=null)
					rs.close();
				if (pstmt!=null)
					pstmt.close();
				if(conn!=null)
					conn.close();
			%>
		</div>
		<hr>
		<jsp:include page="footer.jsp"/>
	</div>
</body>
</html>
