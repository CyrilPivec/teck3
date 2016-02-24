angular.module('starter')

.service('UserService', function($http, Backand) {
  var service = this,
      baseUrl = '/1/objects/',
      objectName = 'User/';

  function getUrl() {
    return Backand.getApiUrl() + baseUrl + objectName;
  }

  function getUrlForId(id) {
    return getUrl() + id;
  }

  service.all = function() {
    return $http.get(getUrl());
  };

  service.fetch = function(id) {
    return $http.get(getUrlForId(id));
  };

  service.create = function(object) {
    return $http.post(getUrl(), object);
  };

  service.update = function(id, object) {
    return $http.put(getUrlForId(id), object);
  };

  service.delete = function(id) {
    return $http.delete(getUrlForId(id));
  };

})

.service('AuthService', function($http, Backand) {
  var self = this;
  var baseUrl = Backand.getApiUrl() + '/1/objects/';
  self.appName = 'nikdev';
  self.login = {};

  function getCurrentUserInfo(email, password) {
    return $http({
      method: 'GET',
      url: baseUrl + "User",
      params: {
        pageSize: 20,
        pageNumber: 1,
        filter: null,
        sort: ''
      }
    }).then(function(response) {
      if (response.data && response.data.data && response.data.data.length > 0) {
        for (var i = 0; i < response.data.data.length; i++) {
          if (response.data.data[i]["email"] == email && response.data.data[i]["password"] == password) {
            return response.data.data[i];
          }
        }
      } else {
        return null;
      }
    });
  }

  self.login = function(email, password, appName) {
    return getCurrentUserInfo(email, password);
  }

})


.service('APIInterceptor', function($rootScope, $q) {
  var service = this;

  service.responseError = function (response) {
    if (response.status === 401) {
      $rootScope.$broadcast('unauthorized');
    }
    return $q.reject(response);
  };
})

.factory('Profiles', function() {
  var profiles = [{
    id: 0,
    nom: "Pivec",
    prenom: "Cyril",
    age: "20",
    face: 'img/ben.png'
  }];

  return {
    all: function() {
      return profiles;
    },
    remove: function(profile) {
     profiles.splice(profiles.indexOf(profile), 1);
   },
    get: function(profileId) {
      for (var i = 0; i < profiles.length; i++) {
       if (profiles[i].id === parseInt(profileId)) {
         return profiles[i];
       }
     }
     return null;
    }
  };
})

.factory('Parties', function() {
  var parties = [{
    id: 0,
    name: 'Niska Charo Life',
    date: '26/02/2016',
    place: 'Kufa Saarbrucken',
    adresse: 'Dudweiler Landstraße 7, 66123 Saarbrücken, Allemagne',
    tel: '+49 6851 9398110',
    description: 'Le rappeur Niska à la Kufa',
    face: 'img/kufa.jpg'
  }, {
    id: 1,
    name: 'Les loges d\'hiver',
    date : '05/03/2016',
    place: 'Les loges',
    adresse: '40 Avenue Paul Langevin, 57070 Saint-Julien-lès-Metz',
    tel: '03 87 37 80 28',
    description: 'Entrée gratuites pour tous avant 1h00',
    face: 'img/loges.jpg'
  }, {
    id: 2,
    name: 'Brasil night',
    date: '26/02/2016',
    place: 'Love boat',
    adresse: '23 Rue Gustave Simon, 54000 Nancy',
    tel: '03 83 36 40 86',
    description: 'soirée Brasil Night',
    face: 'img/love\ boat.jpg'
  }, {
    id: 3,
    name: 'Young wild and free',
    date: '25/02/2016',
    place: 'l\'envers club',
    adresse: '1 Rue Général Hoche, 54000 Nancy',
    tel: '03 83 40 25 13',
    description: 'Gratuit pour les filles',
    face: 'img/envers.jpg'
  }, {
    id: 4,
    name: 'Projet X',
    date: '04/03/2016',
    place: 'Le Chat Noir',
    adresse: '63 Rue Jeanne d\'Arc, 54000 Nancy',
    tel: '03 83 28 49 29',
    description: 'Soirée projet X avec chateau gonflable',
    face: 'img/chat.jpg'
  }];

  return {
    all: function() {
      return parties;
    },
    remove: function(party) {
      parties.splice(parties.indexOf(party), 1);
    },
    get: function(partyId) {
      for (var i = 0; i < parties.length; i++) {
        if (parties[i].id === parseInt(partyId)) {
          return parties[i];
        }
      }
      return null;
    }
  };
})

.factory('Chats', function() {
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
    name: 'Nawin Kim',
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
})

.factory('Markers', function($http) {
  var markers = [];
  return {
    getMarkers: function() { 
      return $http.get("http://example.com/markers.php").then(function(resp) {
          markers = resp;
          return markers;
      });
 
    }

  }
})

.factory('GoogleMaps', function($cordovaGeolocation, Markers) {
 
  var apiKey = false;
  var map = null;
 
  function initMap() {
 
    var options = {timeout: 10000, enableHighAccuracy: true};
 
    $cordovaGeolocation.getCurrentPosition(options).then(function(position) {
      var latLng = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
      var mapOptions = {
        center: latLng,
        zoom: 15,
        mapTypeId: google.maps.MapTypeId.ROADMAP
      }; 
      map = new google.maps.Map(document.getElementById("map"), mapOptions);
      //Wait until the map is loaded
      google.maps.event.addListenerOnce(map, 'idle', function() {
        //Load the markers
        loadMarkers();
      });
 
    }, function(error){
      console.log("Could not get location");
        //Load the markers
        loadMarkers();
    });
  }
 
  function loadMarkers() {
      //Get all of the markers from our Markers factory
      Markers.getMarkers().then(function(markers){
        console.log("Markers: ", markers); 
        var records = markers.data.result;
        for (var i = 0; i < records.length; i++) {
          var record = records[i];   
          var markerPos = new google.maps.LatLng(record.lat, record.lng);
          // Add the markerto the map
          var marker = new google.maps.Marker({
              map: map,
              animation: google.maps.Animation.DROP,
              position: markerPos
          });
 
          var infoWindowContent = "<h4>" + record.name + "</h4>";          
          addInfoWindow(marker, infoWindowContent, record);
        }
      }); 
  }
 
  function addInfoWindow(marker, message, record) {
      var infoWindow = new google.maps.InfoWindow({
          content: message
      }); 
      google.maps.event.addListener(marker, 'click', function () {
          infoWindow.open(map, marker);
      }); 
  }
 
  return {
    init: function(){
      initMap();
    }
  }
})

.service('LoginService', function(Backand) {
  var service = this;

  service.login = function (email, password, appName) {
      //call Backand for sign in
      return Backand.signin(email, password, 'nikdev');
  };

  service.anonymousLogin= function(){
      // don't have to do anything here,
      // because we set app token att app.js
  }

  service.socialLogin = function(provider) {
      return Backand.socialSignIn(provider);
  };

  service.socialRegister = function(provider) {
      return Backand.socialSignUp(provider);
  };

  service.logout = function() {
      return Backand.signout();
  };

  service.register = function(firstName, lastName, email, password, confirmPassword) {
      return Backand.signup(firstName, lastName, email, password, confirmPassword);
  }
})