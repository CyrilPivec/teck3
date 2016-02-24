angular.module('starter')

.controller('RegisterCtrl', function($state, $rootScope, $ionicPopup, UserService, Backand) {
  var ctrl = this;
  
  var onLogin = function() {
    $rootScope.$broadcast('authorized');
    $state.go('login');
  }

  ctrl.register = function(data){
    if (data.password != data.confirmPassword) {
      var alertPopup = $ionicPopup.alert({
        title: 'Register failed!',
        template: 'Password does not match!'
      });
      return;
    }
    var pro = false;
    if (ctrl.choice == "pro") {
      pro = true;
    }
    console.log(ctrl.choice);
    var obj = {"firstname" : data.firstname,
               "lastname" : data.firstname,
               "email" : data.email,
               "password" : data.password,
               "is_pro" : pro
    };
    UserService.create(obj)
      .then(function(response) {
          // success
          onLogin();
      }, function(reason) {
          errorMessage = '';
          if(reason.data.error_description !== undefined){
            errorMessage = reason.data.error_description;
          }
          else {
            errorMessage = reason.data;
          }
          console.log(errorMessage);
          var alertPopup = $ionicPopup.alert({
              title: 'Register failed!',
              template: 'User already exists!'
          });

      });
  }
})