<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>帮助页面</title>
<link rel="stylesheet" href="css/bootstrap.min.css">
<script src="jquery/jquery-3.3.1.min.js"></script>
<script src="js/bootstrap.min.js"></script>
<script src="js/Help.js"></script>
<link href="css/Help.css" rel="stylesheet" type="text/css">
</head>
<body>
<div id="logmessge">
	<button type="button" class="btn btn-lg " >
		用户名：<span id="adminUser"><%=session.getAttribute("adminUser") %></span>
      	登录时间：<span id="logTime"><%=session.getAttribute("logTime") %></span>
      	管理权限：<span id="adminRole"><%=session.getAttribute("adminRole")%></span>
	</button>
</div>
<div id="nav">
	<ul id="nav_ul" class="nav nav-pills nav-justified">
      <li id="nav_ul_li1" role="presentation" class="active"><a href="#">首页</a></li>
      <li id="nav_ul_li2" role="presentation" ><a href="Login.html">登录</a></li>
      <li id="nav_ul_li3" role="presentation"><a href="register.html">注册</a></li>
      <li id="nav_ul_li4" role="presentation" ><a href="#">操作</a></li>
      <li id="nav_ul_li5" role="presentation"><a href="#">帮助</a></li>
	</ul>
</div>

<div id="warp" class="jumbotron">
	<div class="container">
      <h1>学生管理系统帮助页面</h1>
      <p></p>
      <br/>
      <h2>如果你想知道怎么使用这个系统，<br/><p></p>请点击这里
      <img src="img/goto.png"></img>
      <a class="btn btn-primary btn-lg" href="#" data-toggle="modal" data-target="#Instruction">使用说明</a>&nbsp;&nbsp;&nbsp;&nbsp;
      </h2>
      <br>
      <h2>如果你想修改学院的信息，<br/><p></p>请点击这里
      <img src="img/goto.png"></img>
      <a class="btn btn-primary btn-lg" href="#" >学院信息</a>&nbsp;&nbsp;&nbsp;&nbsp;ps:如果你有权限的话
      <img src="img/timg.jpg"></img>
      </h2>
      <br>
      <p></p>
      <h2>最后如果你想知道更多关于本系统的信息，<br/><p></p>请点击这里
      <img src="img/goto.png"></img>
      <a class="btn btn-primary btn-lg" href="#" >更多信息</a>&nbsp;&nbsp;&nbsp;&nbsp;
      </h2>
      <br>
      <p></p>
      <h2><span id="spanfeel">觉得这个系统怎么样，评个分?</span>
      <div class="row">
		     <div id="feel" class="col-md-6">
			      <ul id="star" >
				      	<li >
				      		<img id="star_img" src="img/star0.png"></img>
				      	</li>
				      	<li>
				      		<img id="star_img" src="img/star0.png"></img>
				      	</li>
				      	<li>
				      		<img id="star_img" src="img/star0.png"></img>
				      	</li>
				      	<li>
				      		<img id="star_img" src="img/star0.png"></img>
				      	</li>
				      	<li>
				      		<img id="star_img" src="img/star0.png"></img>
				      	</li>
			      </ul>
		     </div>
		     <br/>
		      
		    <a class="btn btn-primary btn-lg col-md-2" href="#" >提交评分</a>&nbsp;&nbsp;&nbsp;&nbsp;
      </div>
      <br/><br/>
      </h2>
  	</div>
</div>


<!--说明书-->
<div class="row">
	<!--遮罩层-->
	<div class="modal fade " id="Instruction" tabindex="-1" role="dialog" aria-labelledby="InstructionTitle" aria-hidden="true">
	    <!-- /.modal -->
	    <div class="modal-dialog ">
	    	<!-- /.modal-主体 -->
	        <div id="modal-content" class="modal-content col-md-12">
	        
	            <div class="modal-header">
	            	<!--关闭按钮和标题-->
	                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
	                <h3 class="modal-title" id="InstructionTitle">使用说明</h3>
	            </div>
	            <!--主体文本  -->
	            <div class="modal-body">
	            	<h3 id="incontent">啊？什么？网络不好我听不见...什么？你要看说明书？嗯(思考中)...噢，说明书啊，什么说明书？？</h3>
				</div>
	            <!--关闭按钮  -->
	            <div class="modal-footer">
	                <button id="conbtn" type="button" class="btn btn-default btn btn-primary btn-lg" >继续观看</button>
	                <button type="button" class="btn btn-default btn btn-primary btn-lg" data-dismiss="modal">我不看了</button>
	                <!--<button type="button" class="btn btn-primary">提交更改</button>-->
	            </div>
	            
	        </div><!-- /.modal-主体 -->
	        
	    </div><!-- /.modal -->
	    
	</div>
	
</div>

</body>
</html>