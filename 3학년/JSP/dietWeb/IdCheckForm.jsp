<%@ page language="java" contentType="text/html; charset=utf-8"%>
<!DOCTYPE html>
<html>
<head>
<script type="text/javascript">   
	var httpRequest = null;            
	
	function getXMLHttpRequest(){ 
		var httpRequest = null;
		
		if(window.ActiveXObject){
			try{
				httpRequest = new ActiveXObject("Msxmk2.XMLHTTP");
			}catch(e){
				try{  
					httpRequest = new ActiveXObject("Microsoft.XMLHTTP")
				}catch(e2){httpRequest=null}
			}
			
		}
		else if(window.XMLHttpRequest){
			httpRequest=new window.XMLHttpRequest();
		}
		return httpRequest;
	}
</script>
<title>Insert title here</title>
</head>
<body>
	중복확인기능입니다.
</body>
</html>
