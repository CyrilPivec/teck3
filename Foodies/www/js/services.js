angular.module('starter.services', [])

.factory( 'plats', function(){

  var plats = [{
    id: 0 ,
    dishName : 'pizza' ,
    pseudo : 'herve' ,
    price : 5 ,
    date : '21/01/16' ,
    picture : 'img/pizza.jpg'
  },

  {
    id: 1,
    dishName : 'tartiflette' ,
    pseudo : 'herve' ,
    price : 10 ,
    date : '21/01/16' ,
    picture : 'img/pizza.jpg'
  }
  ];

  return {
    all: function() {
      return plats;
    },
    
    get: function(platsId) {
      
      for (var i = 0; i < plats.length; i++) {
        if (plats[i].id === parseInt(platsId)) {
          return plats[i];
        }
      }
    }
  };
})


.factory('profils', function() {
  // Might use a resource here that returns a JSON array

  // Some fake testing data
  var profils = [{
    id: 0,
    name: 'Beka',
    firstname: 'Reda',
    sexe : 'M',
    age: 20,
    description : 'jeune rebelle qui suc pa d bite, jaime bucu cusiné la volail mai silimen halal li rest si di la merde pitin',
    face: 'img/ben.png',
    note: 18,
    nb_plat: 6,
    location: 'Nancy, Lorraine, France'


  }, {
    id: 1,
    name: 'Max Lynx',
    lastText: 'Hey, it\'s me',
    face: 'img/max.png'
  }, {
    id: 2,
    name: 'Adam Bradleyson',
    lastText: 'I should buy a boat',
    face: 'img/adam.jpg'
  }, {
    id: 3,
    name: 'Perry Governor',
    lastText: 'Look at my mukluks!',
    face: 'img/perry.png'
  }, {
    id: 4,
    name: 'Mike Harrington',
    lastText: 'This is wicked good ice cream.',
    face: 'img/mike.png'
  }];

  return {
    all: function() {
      return profils;
    },
    remove: function(profil) {
      profils.splice(profils.indexOf(profil), 1);
    },
    get: function(profileId) {
      if (profileId === "current"){
        return profils[0];
      }
      for (var i = 0; i < profils.length; i++) {
        if (profils[i].id === parseInt(profileId)) {
          return profils[i];
        }
      }
      return null;
    }
  };
});
