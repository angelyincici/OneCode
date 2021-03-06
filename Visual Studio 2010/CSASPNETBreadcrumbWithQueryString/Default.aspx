﻿<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="CSASPNETBreadcrumbWithQueryString.Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>动态Breadcrumb</title>
</head>
<body>
    <form id="form1" runat="server">

    <p>这是根页面.</p>

    <asp:SiteMapPath ID="SiteMapPath1" runat="server">
    </asp:SiteMapPath>
    
    <br /><br />

    <asp:GridView ID="gvCategories" runat="server" AutoGenerateColumns="False">
        <Columns>
            <asp:TemplateField HeaderText="分类">
                <ItemTemplate>
                    <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl='<%# String.Format("Category.aspx?name={0}", Container.DataItem) %>'><%# Container.DataItem %></asp:HyperLink>
                </ItemTemplate>
            </asp:TemplateField>
        </Columns>
    </asp:GridView>

    <br /><br />
    <b>另一个页面: 动态创建breadcrumb</b><br />
    <a href="DynamicBreadcrumb.aspx" target="_blank">DynamicBreadcrumb.aspx</a>

    </form>
</body>
</html>
