<?xml version="1.0" encoding="utf-8" standalone="yes" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:output encoding="utf-8" omit-xml-declaration="yes" method="html" indent="yes" 
    doctype-public="-//W3C//DTD HTML 4.01//EN" 
    doctype-system="http://www.w3.org/TR/html4/strict.dtd" />

<xsl:template match="/">
<HTML>
<HEAD>
<META http-equiv="Content-Style-Type" content="text/css" />
<TITLE>Test Report</TITLE>
<STYLE type="text/css">
H1              { color:#111; font-family:'Times',serif; border-bottom:solid 3px #88A; }
H2              { color:#222; font-family:'Times',serif; border-bottom:solid 2px #88A; }

SPAN.good       { color:#066; font-weight:bold; }
SPAN.critical   { color:#800; font-weight:bold; }

TABLE          	{ color:#222; font-size:10pt; font-family:sans-serif; }
TH             	{ font-weight:normal; color:#FFF; background-color:#666; }
TD              { vertical-align:top; }
TD.num         	{ text-align:right; }
TR.check        { background-color:#EEE; }

TABLE.bar      	{ width:80ex; height:1.2ex; border-spacing:1px; }
TD.successful   { background-color:#088; }
TD.failed      	{ background-color:#C00; }
</STYLE>
</HEAD>
<BODY>
    <H1>Test Report</H1>
    <TABLE class="bar">
        <TR>
            <xsl:for-each select="//SuccessfulTests/Test">
                <TD class="successful"> </TD>
            </xsl:for-each>
            <xsl:for-each select="//FailedTests/FailedTest">
                <TD class="failed"> </TD>
            </xsl:for-each>
        </TR>
    </TABLE>
    <xsl:apply-templates select="/TestRun/*"/>
</BODY>
</HTML>
</xsl:template>

<xsl:template match="FailedTests">
    <H2>FailedTests</H2>
    <xsl:choose>
        <xsl:when test="FailedTest">
            <TABLE>
                <TR>
                    <TH>id</TH>
                    <TH>Name</TH>
                    <TH>FailureType</TH>
                    <TH>Location</TH>
                    <TH>Message</TH>
                </TR>
                <xsl:apply-templates select="FailedTest"/>
            </TABLE>
        </xsl:when>
        <xsl:otherwise>
            <SPAN class="good">No failed test.</SPAN>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="FailedTest">
    <TR>
        <xsl:if test="0 = position() mod 2"><xsl:attribute name="class">check</xsl:attribute></xsl:if>
        <TD class="num"><xsl:value-of select="@id"/></TD>
        <TD><xsl:apply-templates select="Name"/></TD>
        <TD><xsl:apply-templates select="FailureType"/></TD>
        <TD><xsl:apply-templates select="Location"/></TD>
        <TD><PRE><xsl:apply-templates select="Message"/></PRE></TD>
    </TR>
</xsl:template>
<xsl:template match="Name|FailureType|Message"><xsl:value-of select="."/></xsl:template>
<xsl:template match="Location">
    <xsl:if test=".">
        line #<xsl:value-of select="Line"/> in <xsl:value-of select="File"/>
    </xsl:if>
</xsl:template>
  
<xsl:template match="SuccessfulTests">
    <H2>SuccessfulTests</H2>
    <xsl:choose>
        <xsl:when test="Test">
            <TABLE>
                <TR>
                    <TH>id</TH>
                    <TH>Name</TH>
                </TR>
                <xsl:apply-templates select="Test"/>
            </TABLE>
        </xsl:when>
        <xsl:otherwise>
            <SPAN class="critical">No sucessful test.</SPAN>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="Test">
    <TR>
        <xsl:if test="0 = position() mod 2"><xsl:attribute name="class">check</xsl:attribute></xsl:if>
        <TD class="num"><xsl:value-of select="@id"/></TD>
        <TD><xsl:apply-templates select="Name"/></TD>
    </TR>
</xsl:template>

<xsl:template match="Statistics">
    <H2>Statistics</H2>
    <TABLE>
        <TR>
            <TH>Status</TH>
            <TH>Number</TH>
        </TR>
        <TR>
            <TD>Tests</TD>
            <TD class="num"><xsl:value-of select="Tests"/></TD>
        </TR>
        <TR class="check">
            <TD>FailuresTotal</TD>
            <TD class="num"><xsl:value-of select="FailuresTotal"/></TD>
        </TR>
        <TR>
            <TD>Errors</TD>
            <TD class="num"><xsl:value-of select="Errors"/></TD>
        </TR>
        <TR class="check">
            <TD>Failures</TD>
            <TD class="num"><xsl:value-of select="Failures"/></TD>
        </TR>
    </TABLE>
</xsl:template>

</xsl:stylesheet>
