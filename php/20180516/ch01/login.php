
?>
<?php 
$Mysqli=new mysqli("localhost","root","123","think");
//获取值
$name=$_POST['c_name'];
$password=$_POST['c_password'];
//如果不为空，查询有没有
if(!empty($name)&&!empty($password)){
    $sql="select * from customer where name='".$name."' and password='".$password."' ";
    echo $sql;
    $rs=$Mysqli->query($sql);
    var_dump($rs);
    if($rs&&$rs->num_rows>0){
            $user=$rs->fetch_array();
            @session_start();
            $_SESSION['c_id']=$user['id'];
            $_SESSION['c_name']=$user['name'];
            echo $_SESSION['c_name'];
            echo"<script language=javascript>alert('登录成功');</script>";
            echo"<script language=javascript>window.location.href='index.php'</script>";
    }else{
        echo"<script language=javascript>alert('用户名或密码错误');</script>";
        echo"<script language=javascript>window.location.href='login.html'</script>";
    }
}else{
    echo"<script language=javascript>alert('用户名密码不能为空');</script>";
    echo"<script language=javascript>window.location.href='login.html'</script>";
}
?>