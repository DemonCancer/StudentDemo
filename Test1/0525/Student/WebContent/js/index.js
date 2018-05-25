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
			alert("已经登录过,是否退出当前账号");
		}else{
			window.location.href = "Login.jsp";
		}
	});
	$("#nav_ul_li3").click(function (){
		if($("#adminUser").text()!="null"){
			alert("已有学号登录,是否退出当前账号");
		}else{
			window.location.href = "Register.jsp";
		}
	});
	$("#nav_ul_li4").click(function (){
		if($("#adminUser").text()==null||$("#adminUser").text()=="null"){
			  alert("未登录!");
			  window.location.href = "Login.jsp";
		  }else{
			  $(this).tab('show');
			  window.location.href = "StuList.jsp";
		  }
	});
	$("#nav_ul_li5").click(function (){
			  $(this).tab('show');
	});
	$("#gowhere").click(function (){
		  if($("#adminUser").text()==null||$("#adminUser").text()=="null"){
			  window.location.href = "Login.jsp";
		  }else{
			  window.location.href = "StuList.jsp";
		  }
	});
	
});