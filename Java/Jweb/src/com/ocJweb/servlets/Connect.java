package com.ocJweb.servlets;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.ocJweb.clas.User;
import com.ocJweb.clas.Utilisateur;

/**
 * Servlet implementation class Connect
 */
@WebServlet("/Connect")
public class Connect extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Connect() {
        super();
        // TODO Auto-generated constructor stub
    }

    
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		User user = new User();
		request.setAttribute("utilisateurs", user.recupererUtilisateur());
		this.getServletContext().getRequestDispatcher("/WEB-INF/connect.jsp").forward(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String mail = request.getParameter("mail");
        String mdp = request.getParameter("mdp");
        
        HttpSession session = request.getSession();

        User user = new User();
        Utilisateur utilisateur = user.getUser(mail, mdp);
        
        if (utilisateur == null){
        	session.setAttribute("user", null);
        	session.setAttribute("bad", mdp);
        }
        else {
        	session.setAttribute("user", utilisateur);
        	session.setAttribute("bad", null);
        }
        
        this.getServletContext().getRequestDispatcher("/WEB-INF/connect.jsp").forward(request, response);
		 	}

}
