angular.module('starter.services', [])

.factory('Profils', function() {
  var profils = [{
    id: 0,
    nom: "Pivec",
    prenom: "Cyril",
    age: "20",
    face: 'img/ben.png'
  }];

  return {
    all: function() {
      return profils;
    },
    remove: function(profil) {
     profils.splice(profils.indexOf(profil), 1);
   },
   get: function(profilId) {
      for (var i = 0; i < profils.length; i++) {
       if (profils[i].id === parseInt(profilId)) {
         return profils[i];
       }
     }
     return null;
    }
  };
})

.factory('Partys', function() {
  // Might use a resource here that returns a JSON array

  // Some fake testing data
  var partys = [{
    id: 0,
    name: 'Niska Charo Life',
    lieu: 'Kufa Saarbrucken',
    face: 'img/kufa.jpg'
  }, {
    id: 1,
    name: 'Fabien fait le show',
    lieu: 'L\'Endroit Nancy',
    face: 'img/endroit.jpg'
  }, {
    id: 2,
    name: 'Soirée pas loué',
    lieu: 'Champ élysée',
    face: 'img/champ.jpg'
  }, {
    id: 3,
    name: 'gamos sur les champs',
    lieu: 'l\'envers club',
    face: 'img/envers.jpg'
  }, {
    id: 4,
    name: 'Projet X',
    lieu: 'Le Chat Noir',
    face: 'img/chat.jpg'
  }];

  return {
    all: function() {
      return partys;
    },
    remove: function(party) {
      partys.splice(partys.indexOf(party), 1);
    },
    get: function(partyId) {
      for (var i = 0; i < partys.length; i++) {
        if (partys[i].id === parseInt(partyId)) {
          return partys[i];
        }
      }
      return null;
    }
  };
})

.factory('Chats', function() {
  // Might use a resource here that returns a JSON array

  // Some fake testing data
  var chats = [{
    id: 0,
    name: 'Cyril Pivec',
    lastText: 'On va en boite?',
    face: 'img/ben.png'
  }, {
    id: 1,
    name: 'Fabien Bertinelli',
    lastText: 'Hey, it\'s me je suis roux',
    face: 'img/max.png'
  }, {
    id: 2,
    name: 'Reda Beka',
    lastText: 'Je pecho des 2000',
    face: 'img/adam.jpg'
  }, {
    id: 3,
    name: 'Nawim Kim',
    lastText: 'Tchintchong Matuidi charo',
    face: 'img/perry.png'
  }, {
    id: 4,
    name: 'Florian Tousch',
    lastText: 'Viens on va au bar ya de la shneck',
    face: 'img/mike.png'
  }];

  return {
    all: function() {
      return chats;
    },
    remove: function(chat) {
      chats.splice(chats.indexOf(chat), 1);
    },
    get: function(chatId) {
      for (var i = 0; i < chats.length; i++) {
        if (chats[i].id === parseInt(chatId)) {
          return chats[i];
        }
      }
      return null;
    }
  };
});
