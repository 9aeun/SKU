<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@ page import = "java.net.URLEncoder" %>
<%
	request.setCharacterEncoding("UTF-8");

	Cookie cartId = new Cookie("Shipping_cartId", URLEncoder.encode(request.getParameter("cartId"), "utf-8"));
	Cookie name = new Cookie("Shipping_name", URLEncoder.encode(request.getParameter("name"), "utf-8"));
	Cookie shippingDate = new Cookie("Shipping_shippingDate", URLEncoder.encode(request.getParameter("shippingDate"), "utf-8"));
	Cookie country = new Cookie("Shipping_country", URLEncoder.encode(request.getParameter("country"), "utf-8"));
	Cookie zipcode= new Cookie("Shipping_zipcode", URLEncoder.encode(request.getParameter("zipcode"), "utf-8"));
	Cookie address = new Cookie("Shipping_address", URLEncoder.encode(request.getParameter("address"), "utf-8"));
	Cookie detailAddress= new Cookie("Shipping_detailAddress", URLEncoder.encode(request.getParameter("detailAddress"), "utf-8"));
	Cookie reference = new Cookie("Shipping_reference", URLEncoder.encode(request.getParameter("references"), "utf-8"));
	
	cartId.setMaxAge(24 * 60 * 60);
	name.setMaxAge(24 * 60 * 60);
	shippingDate.setMaxAge(24 * 60 * 60);
	country.setMaxAge(24 * 60 * 60);
	zipcode.setMaxAge(24 * 60 * 60);
	address.setMaxAge(24 * 60 * 60);
	detailAddress.setMaxAge(24 * 60 * 60);
	reference.setMaxAge(24 * 60 * 60);
	
	response.addCookie(cartId);
	response.addCookie(name);
	response.addCookie(shippingDate);
	response.addCookie(country);
	response.addCookie(zipcode);
	response.addCookie(address);
	response.addCookie(detailAddress);
	response.addCookie(reference);
	
	response.sendRedirect("orderConfirmation.jsp");
%>
