import { createApp } from 'vue'
import App from './App.vue'
import naive from "naive-ui";
import router from "@/router.ts";
import animated from 'animate.css'

createApp(App).use(router).use(naive).use(animated).mount('#app')
