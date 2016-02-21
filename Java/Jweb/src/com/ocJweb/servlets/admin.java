package com.ocJweb.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.ocJweb.clas.Infos;
import com.ocJweb.clas.Nouvelles;

/**
 * Servlet implementation class admin
 */
@WebServlet("/admin")
public class admin extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public admin() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.getServletContext().getRequestDispatcher("/WEB-INF/admin.jsp").forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Nouvelles nouvelle = new Nouvelles();
		nouvelle.setTitre(request.getParameter("titre"));
		nouvelle.setDescription(request.getParameter("description"));
		nouvelle.setAuteur("admin");
		
		Infos infos = new Infos();
		infos.ajouterNouvelle(nouvelle);
		
		this.getServletContext().getRequestDispatcher("/WEB-INF/news.jsp").forward(request, response);
	}

}
