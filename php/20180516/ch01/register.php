
<?php 
echo "<meta charset='UTF-8'>";
$connect=mysql_connect('localhost','root','123');
//mysql_set_charset("utf8",$connect);

if(!$connect){
    die('数据库连接失败！'.mysql_error());
}

//
$link=mysql_select_db('think',$connect);
if(!$link){
    die('无法连接think表：'.mysql_error());
}
//拿到前台数据
$name=$_POST['c_name'];
$password=md5($_POST['c_password']);
$email=$_POST['c_email'];
$registertime=time();
$status=1;
///不为空就查询数据库看有没有
if(!empty($name)&&!empty($password)&&!empty($email)){
    $sql="select count(*) from customer where name='".$name."'";
    $rs=mysql_query($sql);
    //var_dump($rs);
    $count=mysql_fetch_array($rs);
    ///查到了重填,没查到注册
    if($count[0]>0){
        echo "<script language=javascript>alert('用户名已存在，请换一个');</script>";
        echo"<script language=javascript>window.location.href='register.html'</script>";
    }
    else{
        $sql="insert into customer(name,password,registertime,status,email)".
            "values('".$name."','".$password."','".$registertime."','".$status."','".$email."')";
        echo $sql;
        $rs=mysql_query($sql);
        ///
        if($rs){
            echo"<script language=javascript>alert('注册成功');</script>";
            echo"<script language=javascript>window.location.href='login.html'</script>";
        }else{
            echo"<script language=javascript>alert('系统异常，失败');</script>";
            echo"<script language=javascript>window.location.href='register.html'</script>";
        }
    }
    ///
}else{
    echo"<script language=javascript>alert('用户名,密码，邮箱不能为空');</script>";
    echo"<script language=javascript>window.location.href='register.html'</script>";
}




?>