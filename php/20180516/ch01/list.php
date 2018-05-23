<html>
<head>
  <meta http-equiv=Content-Type content="text/html; charset=utf-8" >
  <title>新闻网站</title>
  <link href="./main.css" rel="stylesheet" type="text/css" />

</head>

<!-- 应用数组开始 -->
<?php
    $menu=array(
        array('id'=>1,'name'=>'时政新闻'),
        array('id'=>2,'name'=>'国际新闻'),
        array('id'=>3,'name'=>'体育新闻'),
        array('id'=>4,'name'=>'娱乐新闻'),
        array('id'=>5,'name'=>'教育新闻'),
        array('id'=>6,'name'=>'游戏新闻')
    );
    $news=array(
	    array('id'=>1,'type'=>1,'title'=>'时政-测试新闻1','time'=>'2016-4-14','nums'=>'5','message'=>'时政-测试新闻的新闻内容'),
	    array('id'=>2,'type'=>1,'title'=>'时政-测试新闻2','time'=>'2016-4-14','nums'=>'2','message'=>'时政-测试新闻的新闻内容'),
	    array('id'=>3,'type'=>1,'title'=>'时政-测试新闻3','time'=>'2016-4-13','nums'=>'6','message'=>'时政-测试新闻的新闻内容'),
	    array('id'=>4,'type'=>1,'title'=>'时政-测试新闻4','time'=>'2016-4-13','nums'=>'7','message'=>'时政-测试新闻的新闻内容'),
	    array('id'=>5,'type'=>1,'title'=>'时政-测试新闻5','time'=>'2016-4-12','nums'=>'1','message'=>'时政-测试新闻的新闻内容'),
	    array('id'=>6,'type'=>2,'title'=>'国际-测试新闻1','time'=>'2016-4-14','nums'=>'1','message'=>'国际-测试新闻的新闻内容'),
	    array('id'=>7,'type'=>2,'title'=>'国际-测试新闻2','time'=>'2016-4-13','nums'=>'4','message'=>'国际-测试新闻的新闻内容'),
	    array('id'=>8,'type'=>2,'title'=>'国际-测试新闻3','time'=>'2016-4-13','nums'=>'3','message'=>'国际-测试新闻的新闻内容'),
	    array('id'=>9,'type'=>2,'title'=>'国际-测试新闻4','time'=>'2016-4-11','nums'=>'2','message'=>'国际-测试新闻的新闻内容'),
	    array('id'=>10,'type'=>2,'title'=>'国际-测试新闻5','time'=>'2016-4-11','nums'=>'5','message'=>'国际-测试新闻的新闻内容'),
	    array('id'=>11,'type'=>3,'title'=>'体育-测试新闻1','time'=>'2016-4-13','nums'=>'5','message'=>'体育-测试新闻的新闻内容'),
	    array('id'=>12,'type'=>3,'title'=>'体育-测试新闻2','time'=>'2016-4-12','nums'=>'5','message'=>'体育-测试新闻的新闻内容'),
	    array('id'=>13,'type'=>3,'title'=>'体育-测试新闻3','time'=>'2016-4-11','nums'=>'5','message'=>'体育-测试新闻的新闻内容'),
	    array('id'=>14,'type'=>3,'title'=>'体育-测试新闻4','time'=>'2016-4-11','nums'=>'5','message'=>'体育-测试新闻的新闻内容'),
	    array('id'=>15,'type'=>3,'title'=>'体育-测试新闻5','time'=>'2016-4-11','nums'=>'5','message'=>'体育-测试新闻的新闻内容'),
	    array('id'=>16,'type'=>4,'title'=>'娱乐-测试新闻1','time'=>'2016-4-13','nums'=>'5','message'=>'娱乐-测试新闻的新闻内容'),
	    array('id'=>17,'type'=>4,'title'=>'娱乐-测试新闻2','time'=>'2016-4-13','nums'=>'5','message'=>'娱乐-测试新闻的新闻内容'),
	    array('id'=>18,'type'=>4,'title'=>'娱乐-测试新闻3','time'=>'2016-4-12','nums'=>'5','message'=>'娱乐-测试新闻的新闻内容'),
	    array('id'=>19,'type'=>4,'title'=>'娱乐-测试新闻4','time'=>'2016-4-11','nums'=>'5','message'=>'娱乐-测试新闻的新闻内容'),
	    array('id'=>20,'type'=>4,'title'=>'娱乐-测试新闻5','time'=>'2016-4-11','nums'=>'5','message'=>'娱乐-测试新闻的新闻内容'),
        array('id'=>21,'type'=>5,'title'=>'教育-测试新闻1','time'=>'2016-4-13','nums'=>'6','message'=>'教育-测试新闻的新闻内容'),
        array('id'=>22,'type'=>5,'title'=>'教育-测试新闻2','time'=>'2016-4-13','nums'=>'6','message'=>'教育-测试新闻的新闻内容'),
        array('id'=>23,'type'=>5,'title'=>'教育-测试新闻3','time'=>'2016-4-12','nums'=>'6','message'=>'教育-测试新闻的新闻内容'),
        array('id'=>24,'type'=>5,'title'=>'教育-测试新闻4','time'=>'2016-4-11','nums'=>'6','message'=>'教育-测试新闻的新闻内容'),
        array('id'=>25,'type'=>5,'title'=>'教育-测试新闻5','time'=>'2016-4-11','nums'=>'6','message'=>'教育-测试新闻的新闻内容'),
        array('id'=>26,'type'=>6,'title'=>'游戏-测试新闻1','time'=>'2016-4-13','nums'=>'7','message'=>'游戏-测试新闻的新闻内容'),
        array('id'=>27,'type'=>6,'title'=>'游戏-测试新闻2','time'=>'2016-4-13','nums'=>'7','message'=>'游戏-测试新闻的新闻内容'),
        array('id'=>28,'type'=>6,'title'=>'游戏-测试新闻3','time'=>'2016-4-12','nums'=>'7','message'=>'游戏-测试新闻的新闻内容'),
        array('id'=>29,'type'=>6,'title'=>'游戏-测试新闻4','time'=>'2016-4-11','nums'=>'7','message'=>'游戏-测试新闻的新闻内容'),
        array('id'=>30,'type'=>6,'title'=>'游戏-测试新闻5','time'=>'2016-4-11','nums'=>'7','message'=>'游戏-测试新闻的新闻内容')
	);
    $link=array(
        array('link'=>'http://www.121ugrow.com/','name'=>'英谷教育'),
        array('link'=>'http://www.baidu.com/','name'=>'百度'),
        array('link'=>'http://www.taobao.com/','name'=>'淘宝'),
        array('link'=>'http://www.sina.com/','name'=>'新浪')
    );
?>
<!-- 应用数组结束 -->
<body>
<div class="contain">
<!-- header开始 -->
  <div class="logo"><a href="myindex.php"></a></div>
  <div class="menu">
    <ul >
<?php 
$Mysqli=new mysqli("localhost","root","123","think");
$sql="select * from type where status='1' ";
$rs=$Mysqli->query($sql);
while($menu=$rs->fetch_array()){
    echo "<li><span>|&nbsp;&nbsp;<span>
              <a href='list.php?id=".$menu['id']."'>"
            .$menu['name']."</a></li>";
}



	/* $t_id=$_GET['id'];
	foreach($menu as $key => $list){
	    if($t_id==$list['id']){
	        $typename=$list['name'];
	    }
		     echo "<li><span>|&nbsp;&nbsp;<span>
              <a href='list.php?id=".$list['id']."'>"
              .$list['name']."</a></li>";
	}  */
?>			
	</ul>		
	<ul id="login">	
	  <li><a href="register.html" target="_self">注册</a></li>
	  <li><a href="login.html" target="_self">登录</a></li>			
	</ul>		
  </div>
  <div class="line1" ></div>
	<div class="main">
	  <div class="select">
	    <form action="#" method="post" >
		  <div class="select_left">
		    <strong>搜索:</strong>
			<input name="keyword" placeholder="请输入关键字"/>
		  </div>
		  <div class="select_right">
			<input name="Submit" type="Submit"  value="立即搜索"  />
		  </div>
		</form>		
	  </div>
	  <div class="currect_position">
		    当前位置：<a href="myindex.php">新闻网站</a>&nbsp;>&nbsp;
			  <?php echo $typename;?>
		</div>
	  <div style="clear: both;"></div>
<!-- header结束 -->

<!-- 页面主要内容开始 -->		
		<div class="details" >
<?php 
	foreach($news as $key=>$list){
	   if($t_id==$list['type']){
?>		    
		  <table>
			<tr>
			  <td>
			     <a href='details.php?n_id=<?php echo $list['id']; ?>'><?php echo $list['title']; ?></a>
			  </td>
	        </tr>
			<tr>
			  <td>
			    <font color='#8F8C89'>日期：<?php echo $list['date']; ?>点击：<?php echo $list['nums']; ?></font>
			  </td>
			</tr>
			<tr>
			  <td><?php echo $list['message']; ?></td>
			</tr>
		  </table>
		  <div class='line2' ></div>
<?php 
	   } 
	}
?>
		</div>
	</div>
<!-- 页面主要内容结束 -->
<!-- footer开始 -->			
	<div class="footer">
<?php 
 
  $num=count($link);
  for($i=0;$i<=$num-1;$i++){
    if($i<$num-1){
        echo "<a href='". $link[$i]['link'] ."'>";
        echo $link[$i]['name']."</a>";
        echo ' | ';
    }else{
        echo "<a href='". $link[$i]['link'] ."'>";
        echo $link[$i]['name']."</a>";
    }
  }
?>
  </div>
</div>
</body>
</html>