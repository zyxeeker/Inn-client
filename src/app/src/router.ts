// Vue Router 4
import {createRouter, createWebHashHistory} from "vue-router";
// @ts-ignore
import {Channel} from "./components/channel/index.ts";
// @ts-ignore
import {Home, GroupHome} from "./components/page/index.ts";
// @ts-ignore
import {Group} from "./components/layout/index.ts"

export default createRouter({
    history: createWebHashHistory(),
    routes: [{
        path: '',
        components: {'Room': Home}
    }, {
        path: '/group/:id',
        name: 'switchGroup',
        components: {'Room': Group},
        children: [{
            path: '',
            components: {'Content': GroupHome}
        }, {
            path: '/group/:id/channel',
            name: 'switchChannel',
            components: {'Content': Channel}
        }]
    }]
});
