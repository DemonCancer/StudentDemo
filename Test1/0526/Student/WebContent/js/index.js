// JavaScript Document
$(document).ready(function(){
	if($("#adminUser").text()!="null"){
		$("#gowhere").text("去操作");
	}
	if($("#adminRole").text()=="true"){
		$("#adminRole").text("有");
	}else{
		$("#adminRole").text("无");
	}
  $("#nav_ul_li1").click(function (){
		$(this).tab('show');
	});
	$("#nav_ul_li2").click(function (){
		if($("#adminUser").text()!="null"){
			if(confirm("已经登录过,是否退出当前账号?")){
				$.ajax({
					type: "post",      
					url: "ExitloginServlet", 
					success : function(Result)
					{
						window.location.href = "Login.jsp";
						
					},
					error : function()
					{
						 alert("数据传输失败!");
					}
				});
			}
		}else{
			window.location.href = "Login.jsp";
		}
	});
	$("#nav_ul_li3").click(function (){
		if($("#adminUser").text()!="null"){
			if(confirm("已经登录过,是否退出当前账号?")){
				$.ajax({
					type: "post",      
					url: "ExitloginServlet", 
					success : function(Result)
					{
						window.location.href = "Register.jsp";
						
					},
					error : function()
					{
						 alert("数据传输失败!");
					}
				});
			}
		}else{
			window.location.href = "Register.jsp";
		}
	});
	$("#nav_ul_li4").click(function (){
		if($("#adminUser").text()==null||$("#adminUser").text()=="null"){
			  alert("未登录!");
			  window.location.href = "Login.jsp";
		  }else{
			  
			  if($("#adminRole").text()=="有"){
				  $(this).tab('show');
				  window.location.href = "StuList.jsp";
			  }else{
				  alert("没有权限!");
				  
			  }
			  
		  }
	});
	$("#nav_ul_li5").click(function (){
		$(this).tab('show');
		window.location.href = "Help.jsp";
	});
	$("#gowhere").click(function (){
		  if($("#adminUser").text()==null||$("#adminUser").text()=="null"){
			  window.location.href = "Login.jsp";
		  }else{
			  if($("#adminRole").text()=="有"){
				  window.location.href = "StuList.jsp";
			  }else{
				  alert("没有权限!");
				  
			  }
		  }
	});
	
});