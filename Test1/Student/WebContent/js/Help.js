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
	//////
	
	
	$("#conbtn").click(function(){
		$("#incontent").html("不用点了，我真不知道什么说明书啊...");
		$(this).text("我非要看");
	});
});