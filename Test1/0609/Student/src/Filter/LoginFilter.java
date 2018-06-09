package Filter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebFilter("")
public class LoginFilter implements Filter{

	@Override
	public void destroy() {
		
		
	}
	
	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain chain) throws IOException, ServletException {
		/*HttpServletRequest req = (HttpServletRequest) request;
		HttpServletResponse res = (HttpServletResponse) response;
		String uri = req.getRequestURI();
		HttpSession session = req.getSession();
		if (uri.endsWith("Login.html") || uri.endsWith("index.html")
				|| session.getAttribute("adminUser") != null) {
			chain.doFilter(req, res);
			return;
		}
		else{
			res.sendRedirect("index.html");
		}*/

		
	}

	@Override
	public void init(FilterConfig arg0) throws ServletException {
		
		
	}

}
