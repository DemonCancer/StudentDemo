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
        array('id'=>1,'type'=>1,'author'=>'admin','nums'=>'5','addtime'=>'2016-4-14','title'=>'时政-测试新闻1',
             'message'=>'这是测试新闻的内容<br>这是测试新闻的内容<br>这是测试新闻的内容<br>
                                                  这是测试新闻的内容<br>这是测试新闻的内容<br>这是测试新闻的内容<br>
                                                  这是测试新闻的内容<br>这是测试新闻的内容<br>这是测试新闻的内容<br>
                                                  这是测试新闻的内容<br>这是测试新闻的内容<br>这是测试新闻的内容<br>'),
        array('id'=>2,'type'=>1,'author'=>'tom','$nums'=>'2','addtime'=>'2016-4-14','title'=>'时政-测试新闻2',
             'message'=>'这是测试新闻2的内容<br>这是测试新闻2的内容<br>这是测试新闻2的内容<br>
                                                  这是测试新闻2的内容<br>这是测试新闻2的内容<br>这是测试新闻2的内容<br>
                                                  这是测试新闻2的内容<br>这是测试新闻2的内容<br>这是测试新闻2的内容<br>
                                                 这是测试新闻2的内容<br>这是测试新闻2的内容<br>这是测试新闻2的内容<br>'),
        array('id'=>3,'type'=>1,'author'=>'tom','$nums'=>'2','addtime'=>'2016-4-14','title'=>'时政-测试新闻3',
            'message'=>'这是测试新闻3的内容<br>这是测试新闻3的内容<br>这是测试新闻2的内容<br>
                                                  这是测试新闻3的内容<br>这是测试新闻3的内容<br>这是测试新闻3的内容<br>
                                                  这是测试新闻3的内容<br>这是测试新闻3的内容<br>这是测试新闻3的内容<br>
                                                 这是测试新闻3的内容<br>这是测试新闻3的内容<br>这是测试新闻3的内容<br>'),
        array('id'=>4,'type'=>1,'author'=>'tom','$nums'=>'2','addtime'=>'2016-4-14','title'=>'时政-测试新闻4',
            'message'=>'这是测试新闻4的内容<br>这是测试新闻4的内容<br>这是测试新闻4的内容<br>
                                                  这是测试新闻4的内容<br>这是测试新闻4的内容<br>这是测试新闻4的内容<br>
                                                  这是测试新闻4的内容<br>这是测试新闻4的内容<br>这是测试新闻4的内容<br>
                                                 这是测试新闻4的内容<br>这是测试新闻4的内容<br>这是测试新闻4的内容<br>'),
        array('id'=>5,'type'=>1,'author'=>'tom','$nums'=>'2','addtime'=>'2016-4-14','title'=>'时政-测试新闻5',
            'message'=>'这是测试新闻5的内容<br>这是测试新闻5的内容<br>这是测试新闻5的内容<br>
                                                  这是测试新闻5的内容<br>这是测试新闻5的内容<br>这是测试新闻5的内容<br>
                                                  这是测试新闻5的内容<br>这是测试新闻5的内容<br>这是测试新闻5的内容<br>
                                                 这是测试新闻5的内容<br>这是测试新闻5的内容<br>这是测试新闻5的内容<br>')
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
	foreach($menu as $key => $list){
	    echo "<li><span>|&nbsp;&nbsp;<span>
              <a href='list.php?id=".$list['id']."'>"
              .$list['name']."</a></li>";
	} 
?>			
	 </ul>	
     <ul id="login">	
	  <li><a href="register.html" target="_self">注册</a></li>
	  <li><a href="login.html" target="_self">登录</a></li>			
	 </ul>		
	</div>
    <div class="line1" ></div>
    <div class="main">
        <div class="currect_position">

          当前位置：<a href="myindex.php">新闻网站</a>&nbsp;>&nbsp;
          <?php
            $id=$_GET['n_id'];
            foreach ($news as $key=>$value){
                if($id==$value['id']){
                    $type       =   $value['type'];
                    $author     =   $value['author'];
                    $nums       =   $value['nums'];
                    $addtime    =   $value['addtime'];
                    $message    =   $value['message'];
                    foreach($menu as $k=>$list){
                        if($type==$list['id']){
                            $type_name=$list['name'];
                            $type_id=$list['id'];
                        }
                    }
                    $title=$value['title'];
                }                
            }
            echo "<a href='list.php?id=".$type_id."'>".$type_name."</a>".'&nbsp;>&nbsp;'.$title;
          ?>
        </div>
        <div style="clear: both;"></div>
<!-- header结束 -->
<!-- 页面主要内容开始 -->        
        <div class="details">
            <div class="details_news_title">
                 <?php echo $title; ?>
            </div> 
            <div class="details_news_author">        
                 <span >作者：<?php echo $author; ?> </span> 
                 <span >点击数：<strong ><?php echo $nums;?></strong></span>     
                 <span >发布时间：<?php echo $addtime;?></span>
            </div>   
            <div class="details_news_message">
                  　                    <?php echo $message; ?>
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
</body>
</html>