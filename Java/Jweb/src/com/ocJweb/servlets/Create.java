package com.ocJweb.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.ocJweb.clas.User;
import com.ocJweb.clas.Utilisateur;

/**
 * Servlet implementation class Create
 */
@WebServlet("/Create")
public class Create extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Create() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.getServletContext().getRequestDispatcher("/WEB-INF/create.jsp").forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Utilisateur utilisateur = new Utilisateur();
	
		utilisateur.setNom(request.getParameter("nom"));
		utilisateur.setPrenom(request.getParameter("prenom"));
		utilisateur.setMdp(request.getParameter("mdp"));
		utilisateur.setMail(request.getParameter("mail"));
		utilisateur.setNewsLetter(request.getParameter("newsLetter") != null);
		utilisateur.setAdmin(false);
        
        User user = new User();
        user.ajouterUser(utilisateur);
        
        this.getServletContext().getRequestDispatcher("/WEB-INF/connect.jsp").forward(request, response);
	}

}
