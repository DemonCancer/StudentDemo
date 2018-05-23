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
	   array('id'=>1,'type'=>1,'title'=>'时政-测试新闻1','time'=>'2016-4-14'),
	   array('id'=>2,'type'=>1,'title'=>'时政-测试新闻2','time'=>'2016-4-14'),
	   array('id'=>3,'type'=>1,'title'=>'时政-测试新闻3','time'=>'2016-4-13'),
	   array('id'=>4,'type'=>1,'title'=>'时政-测试新闻4','time'=>'2016-4-13'),
	   array('id'=>5,'type'=>1,'title'=>'时政-测试新闻5','time'=>'2016-4-12'),
	   array('id'=>6,'type'=>2,'title'=>'国际-测试新闻1','time'=>'2016-4-14'),
	   array('id'=>7,'type'=>2,'title'=>'国际-测试新闻2','time'=>'2016-4-13'),
	   array('id'=>8,'type'=>2,'title'=>'国际-测试新闻3','time'=>'2016-4-13'),
	   array('id'=>9,'type'=>2,'title'=>'国际-测试新闻4','time'=>'2016-4-11'),
	   array('id'=>10,'type'=>2,'title'=>'国际-测试新闻5','time'=>'2016-4-11'),
	   array('id'=>11,'type'=>3,'title'=>'体育-测试新闻1','time'=>'2016-4-13'),
	   array('id'=>12,'type'=>3,'title'=>'体育-测试新闻2','time'=>'2016-4-12'),
	   array('id'=>13,'type'=>3,'title'=>'体育-测试新闻3','time'=>'2016-4-11'),
	   array('id'=>14,'type'=>3,'title'=>'体育-测试新闻4','time'=>'2016-4-11'),
	   array('id'=>15,'type'=>3,'title'=>'体育-测试新闻5','time'=>'2016-4-11'),
	   array('id'=>16,'type'=>4,'title'=>'娱乐-测试新闻1','time'=>'2016-4-13'),
	   array('id'=>17,'type'=>4,'title'=>'娱乐-测试新闻2','time'=>'2016-4-13'),
	   array('id'=>18,'type'=>4,'title'=>'娱乐-测试新闻3','time'=>'2016-4-12'),
	   array('id'=>19,'type'=>4,'title'=>'娱乐-测试新闻4','time'=>'2016-4-11'),
	   array('id'=>20,'type'=>4,'title'=>'娱乐-测试新闻5','time'=>'2016-4-11'),
        array('id'=>21,'type'=>5,'title'=>'教育-测试新闻1','time'=>'2016-4-13'),
        array('id'=>22,'type'=>5,'title'=>'教育-测试新闻2','time'=>'2016-4-13'),
        array('id'=>23,'type'=>5,'title'=>'教育-测试新闻3','time'=>'2016-4-12'),
        array('id'=>24,'type'=>5,'title'=>'教育-测试新闻4','time'=>'2016-4-11'),
        array('id'=>25,'type'=>5,'title'=>'教育-测试新闻5','time'=>'2016-4-11'),
        array('id'=>26,'type'=>6,'title'=>'游戏-测试新闻1','time'=>'2016-4-13'),
        array('id'=>27,'type'=>6,'title'=>'游戏-测试新闻2','time'=>'2016-4-13'),
        array('id'=>28,'type'=>6,'title'=>'游戏-测试新闻3','time'=>'2016-4-12'),
        array('id'=>29,'type'=>6,'title'=>'游戏-测试新闻4','time'=>'2016-4-11'),
        array('id'=>30,'type'=>6,'title'=>'游戏-测试新闻5','time'=>'2016-4-11')
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
$sql="select * from type where status='1'";
$rs=$Mysqli->query($sql);
while ($menu=$rs->fetch_array()){
    echo "<li><span>|&nbsp;&nbsp;<span><a href=list.php?id=".$menu['id'].">".$menu['name']."</a></li>";
}
?>			
	</ul>	
	<?php 
	   @session_start();
	   echo "<script language=javascript>alert('".$_SESSION['c_name']."');</script>";
	   if(!isset($_SESSION['c_name'])){
	?>	
	<ul id="login">	
	  <li><a href="register.html" target="_self">注册</a></li>
	  <li><a href="login.html" target="_self">登录</a></li>			
	</ul>
	<?php 
	   }else{
	?>
	<ul id="loged">	
	  <li><a href="login.php?flag=logout" target="_self">退出登录</a></li>
	  <li><a>欢迎您，<?php echo $_SESSION['c_name'];?></a></li>			
	</ul>
	<?php }
	   $rs->close();
	   $Mysqli->close();
	?>	
		
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
	  <div style="clear: both;"></div>
<!-- header结束 -->	  

<!-- 页面主要内容开始 -->	  
	  <div class="main_list" >
	    <div class="main_list_left" >
		  <div class="main_type_title">					
		    <span>时政新闻</span>
			<em><a href="list.php?id=1">更多>></a></em>
		  </div>
	      <div class="main_news_title">
			<ul>	
<?php 
    $Mysqli=new mysqli("localhost","root","123","think");
    $sql="select * from news where type='1' limit 5";
    $rs=$Mysqli->query($sql);
    while ($news=$rs->fetch_array()){
?>
		      <li><a href="details.php?n_id=<?php echo $news['id']; ?>"><?php echo $news['title']; ?></a>
			  <span><font color=#297ad6><?php echo date("Y-m-d",$news['addtime']); ?></font></span>
			  </li>
<?php
    }
?>
            </ul>
		  </div>
		</div>
		<div class="main_list_right">
		  <div class="main_type_title">
            <span style="float:left;">国际新闻</span>
			<em><a href="">更多>></a></em>
		  </div>
		  <div class="main_news_title">
			<ul>
<?php 
    $sql="select * from news where type='2' limit 5";
    $rs=$Mysqli->query($sql);
    while ($news=$rs->fetch_array()){
?>
		      <li><a href="details.php?n_id=<?php echo $news['id']; ?>"><?php echo $news['title']; ?></a>
			  <span><font color=#297ad6><?php echo date("Y-m-d",$news['addtime']); ?></font></span>
			  </li>
<?php
        }

?>

			</ul>
		  </div>
		</div>
	  </div>
		
	  <div class="main_list" >
	    <div class="main_list_left" >
	  	  <div class="main_type_title">					
		    <span>体育新闻</span>
		    <em><a href="">更多>></a></em>
		  </div>
  		  <div class="main_news_title">
			<ul>
<?php 
$sql="select * from news where type='3' limit 5";
$rs=$Mysqli->query($sql);
while ($news=$rs->fetch_array()){
?>
		      <li><a href="details.php?n_id=<?php echo $news['id']; ?>"><?php echo $news['title']; ?></a>
			  <span><font color=#297ad6><?php echo date("Y-m-d",$news['addtime']); ?></font></span>
			  </li>
<?php
        }
?>

			 </ul>
	                     </div>
	  </div>
	  
	  
	  
	  
	  
	  
		  <div class="main_list_right">
		    <div class="main_type_title">
			  <span style="float:left;">娱乐新闻</span>
			  <em style="float:right;"><a href="">更多>></a></em>
		    </div>
		   <div class="main_news_title">
  			  <ul>
<?php 
$sql="select * from news where type='4' limit 5";
$rs=$Mysqli->query($sql);
while ($news=$rs->fetch_array()){
?>
		      <li><a href="details.php?n_id=<?php echo $news['id']; ?>"><?php echo $news['title']; ?></a>
			  <span><font color=#297ad6><?php echo date("Y-m-d",$news['addtime']); ?></font></span>
			  </li>
<?php
        }
        $rs->close();
        $Mysqli->close();
        
?>	
			  </ul>
			</div>
		  </div>
		  
		  
		  
		  
		  
		  
		</div>
		
		
		
		
		
<!-- 页面主要内容结束 -->
<!-- footer开始 -->		
		<div class="footer">
		<?php 
		  $i = 0;
		  $num=count($link);
		  foreach ($link as $key=>$list){
		      $i++;
		      if($num==$i){
		          echo "<a href='". $list['link'] ."'>";
		          echo $list['name']."</a>";
		      }else{
		          echo "<a href='". $list['link'] ."'>";
		          echo $list['name']."</a>";
		          echo ' | ';
		      }      
          }		 
		?>
		</div>
<!-- footer结束 -->	
	</div>
</div>
</body>
</html>