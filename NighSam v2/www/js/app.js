angular.module('starter', ['ionic', 'ngCordova', 'backand'])

.run(function($ionicPlatform, $http) {
  $ionicPlatform.ready(function() {

    if (window.cordova && window.cordova.plugins && window.cordova.plugins.Keyboard) {
      cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);
      cordova.plugins.Keyboard.disableScroll(true);

    }
    if (window.StatusBar) {
      StatusBar.styleDefault();
    }
  });

})

.config(function(BackandProvider, $httpProvider) {
  BackandProvider.setAppName('nikdev');
  BackandProvider.setSignUpToken('3ae0aacb-1d2c-4d3e-988c-931df49595e7'); 
  BackandProvider.setAnonymousToken('cbde00e9-ad65-466f-af8c-688fc7421097'); 
  $httpProvider.interceptors.push('APIInterceptor');
})

.config(function($stateProvider, $urlRouterProvider) {
  $stateProvider

  // setup an abstract state for the tabs directive
  .state('tab', {
    url: '/tab',
    abstract: true,
    templateUrl: 'templates/tabs.html',
    controller: 'TabCtrl as ctrl'
  })

  // Each tab has its own nav history stack:
  .state('login', {
    url: '/login',
    templateUrl: 'templates/login.html',
    controller: 'LoginCtrl as ctrl'
  })

  .state('register', {
    url: '/register',
    templateUrl: 'templates/register.html',
    controller: 'RegisterCtrl as ctrl'
  })

  .state('tab.map', {
    url: '/map',
    views: {
      'tab-map': {
        templateUrl: 'templates/tab-map.html',
        controller: 'MapCtrl as ctrl'
      }
    }
  })

   .state('tab.party', {
    url: '/party',
    views: {
      'tab-party': {
        templateUrl: 'templates/tab-party.html',
        controller: 'PartyCtrl as ctrl'
      }
    }
  })
    
  .state('tab.party-detail', {
    url: '/party/:partyId',
    views: {
      'tab-party': {
        templateUrl: 'templates/party-detail.html',
        controller: 'PartyDetailCtrl'
      }
    }
  })

  .state('tab.offer', {
    url: '/offer',
    views: {
      'tab-offer': {
        templateUrl: 'templates/tab-offer.html',
        controller: 'OfferCtrl as ctrl'
      }
    }
  })

  .state('tab.chats', {
      url: '/chats',
      views: {
        'tab-chats': {
          templateUrl: 'templates/tab-chats.html',
          controller: 'ChatsCtrl as ctrl'
        }
      }
    })

  .state('tab.chat-detail', {
      url: '/chats/:chatId',
      views: {
        'tab-chats': {
          templateUrl: 'templates/chat-detail.html',
          controller: 'ChatDetailCtrl'
        }
      }
    })

  .state('tab.account', {
    url: '/account',
    views: {
      'tab-account': {
        templateUrl: 'templates/tab-account.html',
        controller: 'AccountCtrl as ctrl'
      }
    }
  });

  $urlRouterProvider.otherwise('/login');

})

// .run(function($rootScope, $state, LoginService, Backand) {

//   function unauthorized() {
//     console.log("user is unauthorized, sending to login");
//     $state.go('login');
//   }

//   function logout() {
//     LoginService.logout();
//   }

//   $rootScope.$on('unauthorized', function() {
//       unauthorized();
//   });

//   $rootScope.$on('$stateChangeSuccess', function(event, toState) {
//     if (toState.name == 'login') {
//       logout();
//     }
//     else if (toState.name != 'login' && Backand.getToken() === undefined) {
//       unauthorized();
//     }
//   });
// })