<?xml version="1.0" encoding="euc-kr"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:template match="/">
	<HTML>
	<HEAD>
		<TITLE> simple xslt example </TITLE>
	</HEAD>
	<BODY>
		<xsl:apply-templates select="/simple/name"/>	
	</BODY>
	</HTML>

</xsl:template>

<xsl:template match="name">
	<p><xsl:value-of select="."/></p> <!--현재 노드이므로 "."으로-->
</xsl:template>

</xsl:stylesheet>

