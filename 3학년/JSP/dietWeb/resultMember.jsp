<%@ page contentType="text/html; charset=utf-8"%>
<html>
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
<link rel="stylesheet" href="../resources/css/bootstrap.min.css" />
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Hi+Melody&family=Nanum+Gothic:wght@700&family=Poor+Story&display=swap" rel="stylesheet">
<title>회원 정보</title>
</head>
<body>
	<jsp:include page="/menu.jsp" />
	<div class="jumbotron bg-white">
		<div class="container" style="text-align : center;">
			<img src="./images/logo.png "style ="width:400px" class="center-block">
			<br><br><br>
			<h1 class="display-3" style="font-family: 'Hi Melody', cursive;">회원 정보</h1>
		</div>
		<br><br><br>
		<jsp:include page="/menu3.jsp" />
	</div>
	<div class="container" align="center">
		<%
			String msg = request.getParameter("msg");

			if (msg != null) {
				if (msg.equals("0"))
					out.println(" <h2 class='alert alert-warning'>회원정보가 수정되었습니다.</h2>");
				else if (msg.equals("1"))
					out.println(" <h2 class='alert alert-warning'>회원가입을 축하드립니다.</h2>");
				else if (msg.equals("2")) {
					String loginId = (String) session.getAttribute("sessionId");
					out.println(" <h2 class='alert alert-warning'>" + loginId + "님 환영합니다</h2>");
				}				
			} else {
				out.println("<h2 class='alert alert-warning'>회원정보가 삭제되었습니다.</h2>");
			}
		%>
	</div>	
</body>
</html>
