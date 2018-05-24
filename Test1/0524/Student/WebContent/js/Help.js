$(document).ready(function(){
	/////评分
	$("#star li").mouseenter(function(){
		//alert("ok");
		if($(this).next().children().attr("src")=="img/star1.png"){
			//$(this).nextAll().children().attr("src","img/star0.png");
		}else{
			$(this).children().attr("src","img/star1.png");
			$(this).prevAll().children().attr("src","img/star1.png");
		}
		
		
		});
	/*$("#star li img").mouseleave(function(){
		$(this).attr("src","img/star0.png");
	});*/
	$("#star li").click(function(){
		/*$(this).attr("src","img/star1.png");*/
		$(this).nextAll().children().attr("src","img/star0.png");
		$(this).children().attr("src","img/star1.png");
		
		//$(this).children().attr("src","img/star1.png");
	});
	/////向后台传输数据进行查询专业、
	//var arrprofession = new Array();
	GetProfession();
	//获取专业存到数组里
	function GetProfession(){
		var test="aaa";
		$.ajax({
			//直接"post"或者"get",不需要"doPost","doGet"，该函数到后端接收缓冲区会自动匹配
			type: "post",
			//servlet文件名为Calculator，需要提前在web.xml里面注册
			url: "GetProAllServlet", 
			//数据类型，可以为json，xml等等，自己百度
			dataType:"json",
			data:
			{
				"test":test
			},
			success : function(Result)
			{
				//Result为后端post函数传递来的数据，这里写结果操作代码
				//alert(Result);
				//alert(Result.data[0].id);
				//$("#EditProspan").append("");
				var str=""
				for(var i=0;i<Result.data.length;i++){
					str="<tr><td>"+Result.data[i].id+"</td><td>"+Result.data[i].profession+"</td></tr>";
					$("#protablist").append(str);
				}
				alert($("#protablist").html());
			},
			error : function()
			{
				 alert("数据传输失败!");
			}
		});
	}
	
	
	
	
	
});