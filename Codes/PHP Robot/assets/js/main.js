/*
 *  Robi the PHP robot
 *  A control and login interface
 *  Copyright (c) 2020 Maxim Verhoef
 *  contact@maximverhoef.nl
 */
var inputField = $('input');
$(function() {
    inputField.on('change', function() {
        if (inputField.val().length) {
            inputField.addClass('populated');
        } else {
            inputField.removeClass('populated');
        }
    })
});