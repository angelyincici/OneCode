/********************************* 模块头 *********************************\
模块名:      FileController.cs
项目名:      CSASPNETMVCFileDownload
版权 (c) Microsoft Corporation.

此模块包括FileController类. 

FileController是文件下载功能的专用类.
当请求列表文件, FileController将调用List行为返回文件列表
并通过File/List视图显示

当请求下载指定文件时, FileController将调用Download行为返回
请求文件的流.

This source is subject to the Microsoft Public License.
See http://www.microsoft.com/opensource/licenses.mspx#Ms-PL.
All other rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, 
EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
\***************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Mvc.Ajax;
using System.IO;


namespace CSASPNETMVCFileDownload.Controllers
{
    public class FileController : Controller
    {
        // 列出在"~/App_Data/download" 目录中所有文件的行为
        public ActionResult List()
        {
            // 获取文件列表.
            DirectoryInfo dir = new DirectoryInfo(Server.MapPath("~/App_Data/download/"));

            // 通过LINQ到对象过滤.
            var files = from f in dir.GetFiles("*.*", SearchOption.TopDirectoryOnly)
                        where f.Extension != "exe"
                        select f;

            // 调用关联视图.
            return View(files.ToList());
        }

        // 返回指定文件的二进制流的行为.
        public ActionResult Download(string fn)
        {
            // 检查请求文件是否有效.
            string pfn = Server.MapPath("~/App_Data/download/" + fn);
            if (!System.IO.File.Exists(pfn))
            {
                throw new ArgumentException("Invalid file name or file not exists!");
            }

            // 使用BinaryContentResult封装文件内容并返回.
            return new BinaryContentResult()
            {
                FileName = fn,
                ContentType = "application/octet-stream",
                Content = System.IO.File.ReadAllBytes(pfn)
            };
        }
    }
}
