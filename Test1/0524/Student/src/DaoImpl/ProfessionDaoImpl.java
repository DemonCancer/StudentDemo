package DaoImpl;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import entity.Profession;
import Dao.ProfessionDao;
import util.DBUtil;

public class ProfessionDaoImpl extends DBUtil implements ProfessionDao{
	String  SQL_SELECT= "select "
			+ "id,profession "
			+ "from professiondetail";
	@Override
	public List<Profession> getAllProfession() {
		DBUtil.getConnection();
		List<Profession> proList=new ArrayList<Profession>();
		ResultSet rs = this.executeQuery(SQL_SELECT, new String[] {});
		try {
			while (rs.next()){
				Profession pro=new Profession();
				pro.setId(rs.getInt("id"));
				pro.setProfession(rs.getString("profession"));
				proList.add(pro);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			//关闭连接
			this.closeAll();
		}
		return proList;
	}

}
